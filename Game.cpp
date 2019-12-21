#include "Game.h"
#include <utility>
#include <iostream>


Game::Game(){
  int numOfPlayers = 0;
  std::cout << "Enter num of players(Max 5): ";
  std::cin >> numOfPlayers;
  for(int i = 0; i < numOfPlayers;i++){
    players.push_back(Player(i+1));
    d.dealCards(players[i].getId());
    std::cout << players[i].getId() << "'s cards" << std::endl;
    d.showHand(players[i].getId());
  }
  Round();
  
}

void Game::Playing(){
  for(int i = 0; i <  players.size();i++){
    d.dealCards(players[i].getId());
    d.showHand(players[i].getId());
  }
  //Round of betting
  for(int i = 0;i<players.size();i++){
    if(players[i].getFolded() == false){
      switchCards(players[i].getId());
      d.showHand(players[i].getId());
    }
  }
  //Round of betting
  
  checkWon();


}

int Game::getAllBets(){
  int ret = 0;
  for(int i = 0; i < players.size();i++){
    ret += players[i].getBet();
  }
  return ret;
}

void Game::Round(){
  int maxBet = 0;
  int index = 0;
  for(int i = 0;i < players.size();i++){
    players[i].resetCF();
  }
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
  players[0].setMoney(players[0].getMoney() + pot);
  for(int i = 0; i < players.size();i++){
    std::cout << "Player " << players[i].getId() << "'s Money " << players[i].getMoney() << std::endl;
  }
}



void Game::switchCards(int player){
    int numSwitch = 0;
    std::cout << "How many cards do you want to switch?";
    std::cin >> numSwitch;
    d.switchCard(player,numSwitch);

}

void Game::checkWon(){
   /* 2 for pair
      3 for three of a kind
      4 for two pair
      5 for straight
      7 for full house
      8 for four of a kind
   */
   int cardCount = 0;
   int winning = 1;
   for(int i = 0;i< players.size();i++){
     if(players[i].getCalled() && !players[i].getFolded()){
        if(cardCount < d.checkHand(players[i].getId())){
          winning = players[i].getId();
          cardCount = d.checkHand(players[i].getId());
        }
      }
    }
     std::cout << "Player " << winning << " Won" << std::endl;
   }
  
bool Game::isCalled(){
  for(int i = 0; i< players.size();i++){
      if(players[i].getCalled() == false){
        return false;
      }
  }
  return true;
}


void Game::isPCalled(int maxBet){
    for(int i = 0; i < players.size();i++){
      players[i].checkBet(maxBet);
    }
}

