#include "Game.h"
#include <utility>
#include <iostream>


//Constructor
Game::Game(){

  Network::init(sock,server,"0.0.0.0");
  d.shuffleDeck();
  d.dealCards(1);
  d.getState(1,p);
  d.printDeck();
  int conn = Network::initServer(sock,server);
  Network::sendPokerPacket(conn,p);

  //Inputs number of players in game
  /*int numOfPlayers = 0;
  std::cout << "Enter num of players(Max 5): ";
  std::cin >> numOfPlayers;
  //if There is not at least player theres no point to the game
  //This will be used later maybe for online playing
  if(numOfPlayers < 1){
    return;
  }
  //Resizes player vector 
  players.reserve(numOfPlayers);
  for(int i = 0; i < numOfPlayers;i++){
    players.emplace_back(Player(i+1));
  }*/
  //Runs playing loop
  //While(Game is running){Playing();}
  //Playing();

  
}

//Playing loop
void Game::Playing(){
 /*
  //Shuffles deck
  d.shuffleDeck();
  //Resets called and folded booleans
  for(int i = 0;i < players.size();i++){
    players[i].resetCF();
  }
  //Deals cards to every player and prints them
  for(int i = 0; i <  players.size();i++){
    d.dealCards(players[i].getId());
    std::cout << "Player " << players[i].getId() << " Cards\n";
    d.showHand(players[i].getId());
  }
  //Round of betting
  Round();
  //Switch cards for players who didn't fold
  for(int i = 0;i<players.size();i++){
    if(players[i].getFolded() == false){
      switchCards(players[i].getId());
      d.showHand(players[i].getId());
      players[i].setCalled(false);  
    }
  }
  //Round of betting
  Round();

  //Check who won and change money depending on
  int win = checkWon();
  players[win-1].setMoney(players[win-1].getMoney() + pot);
  for(int i = 0; i < players.size();i++){
    std::cout << "Player " << players[i].getId() << "'s Money" << players[i].getMoney() << std::endl;
  }*/
}

//Gets all players bets
int Game::getAllBets(){
  int ret = 0;
  for(int i = 0; i < players.size();i++){
    ret += players[i].getBet();
  }
  return ret;
}
//Betting round
void Game::Round(){
  for(int i = 0; i < players.size(); i++){
    players[i].setBet(0);
  }
  int maxBet = 0;
  int index = 0;
  while(isCalled() == false){
    maxBet = players[index].Play(maxBet);
    isPCalled(maxBet);
    index++;
    if(index >= players.size()){
      index = 0;
    }
  }
  for(int i = 0; i < players.size(); i++){
    players[i].setMoney(players[i].getMoney() - players[i].getBet()); 
  }
  pot += getAllBets();
}


//Switch cards function
void Game::switchCards(int player){
    int numSwitch = 0;
    std::cout << "How many cards do you want to switch?";
    std::cin >> numSwitch;
    d.switchCard(player,numSwitch);

}
//Check who has the best hand
int Game::checkWon(){
   int cardCount = -1;
   int winning = 1;
   for(int i = 0;i< players.size();i++){
     if(players[i].getCalled() == true && players[i].getFolded() == false){
        if(cardCount < d.checkHand(players[i].getId())){
          std::cout << "Player " << players[i].getId() << " CardCount " <<  d.checkHand(players[i].getId());
          winning = players[i].getId();
          cardCount = d.checkHand(players[i].getId());
        }
      }
    }
  std::cout << "Player " << winning << " Won" << std::endl;
  return winning;
}
  
//Check if everyone is called
bool Game::isCalled(){
  for(int i = 0; i< players.size();i++){
      if(players[i].getCalled() == false){
        return false;
      }
  }
  return true;
}

//Check if you you're bet is called with the highest bet
void Game::isPCalled(int maxBet){
    for(int i = 0; i < players.size();i++){
      players[i].checkBet(maxBet);
    }
}

