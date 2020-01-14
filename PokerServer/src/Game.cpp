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
  
  //Playing Loop Call
  Playing();

  close(sock);
}

void Game::Playing(){
  //Give each player id
  for(int i = 0; i < conns.size();i++){
    int j = i + 1;
    send(conns[i],&j,sizeof(j),0);
  }
  while(1){
  //Deal Cards------------------------------------------
  dealCards();
  //First round of betting-----------------------------
  getBets();
  for(int i = 0; i < conns.size();i++){
    std::cout << "Player number " << players[i].getId() << "'s bet " <<  players[i].getBet() << std::endl;
  }
  std::cout << "Pot is: " << pot << std::endl;
  //Second round of betting-------------------------------
  std::cout << "Round 2" << std::endl;
  for(int i = 0; i < conns.size();i++){
    std::cout << "Deleting " << i << "'s bets" << std::endl;
    players[i].setCalled(false);
    players[i].setBet(0);
  }
  g.maxBet = 0;
  std::cout << "Getting second round of bets" << std::endl;
  getBets();
  for(int i = 0; i < conns.size();i++){
    std::cout << "Player number " << players[i].getId() << "'s bet " <<  players[i].getBet() << std::endl;
  }
  std::cout << "Pot is: " << pot << std::endl;
 
  }
}


bool Game::checkCalled(){
  for(int i = 0; i < players.size();i++){
    players[i].checkBet(g.maxBet);
    if(players[i].getCalled() == false){
      return false;
    }
  }
  return true;
}

void Game::getBets(){
    char exit = ' ';
    int i = 0;
    while(!checkCalled()){
    g.players = players[i];
    Network::sendGameState(conns[i],g);
    Network::recvGameState(conns[i],g);
    players[i] = g.players;
    send(conns[i],&exit,sizeof(exit),0);
    i++;
    if(i >= players.size()){
      i = 0;
    }
  }
  exit = 'q';
  for(int i = 0; i < conns.size();i++){
    send(conns[i],&exit,sizeof(exit),0);
  }
  std::cout << "bababoui babaoui" << std::endl;
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