#include "Game.h"
#include <utility>
#include <iostream>

Game::Game(){
  int numOfPlayers = 0;
  std::cout << "Enter num of players: ";
  std::cin >> numOfPlayers;
  for(int i = 0; i < numOfPlayers;i++){
    players.push_back(Player(i+1,true));
    d.dealCards(players[i].getId());
  }
  checkWon();
}

void Game::Playing(){
  d.printDeck();
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
   int winning = 0;
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
  



void Game::Round(){
   for(int i = 0; i< players.size();i++)
        players[i].resetCF();
   int index = 0;
   int maxBet = 0;
   while(index < players.size()){
      if(isPCOF(index)){
      std::cout << "Players " << index+1 << " turn" << "You have " << players[index].getMoney() << std::endl;
      maxBet = players[index].Play(maxBet);
      index++;
      if(index >= players.size()){
         index = 0;
       }
     }
  }
}
int Game::isPCOF(int i){
    if(players[i].getFolded()){
        return -1;
    }
  
  else if(!players[i].getCalled()){
    return 0;
  }
  return 1;
}
