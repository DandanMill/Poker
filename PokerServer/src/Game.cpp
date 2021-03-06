#include "Game.h"
#include <iostream>

Game::Game(){
  
  Network::init(sock,server,"0.0.0.0");
  std::cout << "How many players are going to be playing? ";
  int option;
  std::cin >> option;
  conns.resize(option);
  players.reserve(option);
  for(int i = 0; i < players.capacity();i++){
    players.emplace_back(Player(i+1));
  }
  Network::initServer(sock,server,conns);
  //Give each player id
  for(int i = 0; i < conns.size();i++){
    int j = i + 1;
    send(conns[i],&j,sizeof(j),0);
  }
  
  //Playing Loop Call
  Playing();

  close(sock);
}

void Game::Playing(){
  while(1){
  for(int i = 0; i < players.size();i++){
    Network::recvGameState(conns[i],g);
    players[i] = g.players;
  }
  //Deal Cards------------------------------------------
  dealCards();
  //First round of betting-----------------------------
  getBets();
  for(int i = 0; i < conns.size();i++){
    if(players[i].getFolded() == true){
      std::cout << "Player number " << players[i].getId() << " is folded" << std::endl;
    }else
    std::cout << "Player number " << players[i].getId() << "'s bet " <<  players[i].getBet() << std::endl;
  }
  std::cout << "Pot is: " << pot << std::endl;
  //Switching cards--------------------------------------
  switchCards();
  //Switching cards---------------------------------------
  //Second round of betting-------------------------------
  std::cout << "Round 2" << std::endl;
  for(int i = 0; i < players.size();i++){
    players[i].setCalled(0);
    players[i].setBet(0);
  }
  g.maxBet = 0;
  getBets();
  for(int i = 0; i < conns.size();i++){
    if(players[i].getFolded() == true){
      std::cout << "Player number " << players[i].getId() << " is folded" << std::endl;
    }else
    std::cout << "Player number " << players[i].getId() << "'s bet " <<  players[i].getBet() << std::endl;
  }
  std::cout << "Pot is: " << pot << std::endl;
  //Check who won-----------------------------
  int winner = checkWon();
  //Update money-----------------------------------------
  players[winner].setMoney(players[winner].getMoney() + pot);
  for(int i = 0; i < players.size();i++){
    std::cout << "Player number " << players[i].getId() << " Has " << players[i].getMoney() << " Chips" << std::endl;
  }
  for(int i = 0; i < players.size();i++){
    char exit;
    if(i == winner){
     exit = 'w';
    }else{
     exit = 'a';
    }
    send(conns[i],&exit,sizeof(char),0);
  }
  }
}

void Game::switchCards()
{
  for(int i = 0; i < players.size();i++){
    if(players[i].getFolded() == false){
      Network::sendGameState(conns[i],g);
      Network::recvGameState(conns[i],g);
    }
  }
}

bool Game::checkCAndF(){
  for(int i = 0; i < players.size();i++){
    players[i].checkBet(g.maxBet);
    if(players[i].getCalled() == false && players[i].getFolded() == false){
      return false;
    }
  }
  return true;
}

int Game::checkWon(){
  int win = 0;
  int winner = -1;
  for(int i = 0; i < players.size();i++){
    if(players[i].getCalled() == true && players[i].getFolded() == false){
    if(g.d.checkHand(players[i].getId()) > win){
      std::cout << "Player number: " << players[i].getId() << "'s hand value " << g.d.checkHand(players[i].getId()) << std::endl;
      winner = i;
      win = g.d.checkHand(players[i].getId());
    }
   }
  }
  return winner;
}

bool Game::onlyPlayer(int i){
  for(int j = i+1;j < players.size();j++){
    if(players[j].getFolded() == false){
      return false;
    }
  }
  for(int j = i-1;j >= 0;j--){
    if(players[j].getFolded() == false){
      return false;
    }
  }
  return true;
}

void Game::getBets(){
    char exit = ' ';
    int i = 0;
    while(!checkCAndF()){
      send(conns[i],&exit,sizeof(exit),0);  
      if(players[i].getFolded() == false){
      g.onlyPlayer = onlyPlayer(i);
      g.players = players[i];
      Network::sendGameState(conns[i],g);
      Network::recvGameState(conns[i],g);
      players[i] = g.players;
      }
      i++;
      if(i >= players.size()){
        i = 0;
       }
      
    }
  exit = 'q';
  for(int i = 0; i < conns.size();i++){
    send(conns[i],&exit,sizeof(exit),0);
    pot += players[i].getBet();
    players[i].setMoney(players[i].getMoney() - players[i].getBet());
  }
}

void Game::dealCards(){
  g.d.shuffleDeck();
  
  for(int i = 1; i <= conns.size();i++){
    g.d.dealCards(i);
  }
  for(int i = 0; i < conns.size();i++){
    Network::sendGameState(conns[i],g);
  }
}