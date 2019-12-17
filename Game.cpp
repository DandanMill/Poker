#include "Game.h"
#include <utility>
#include <iostream>

Game::Game(){
  int numOfPlayers = 0;
  std::cout << "Enter num of players: ";
  std::cin >> numOfPlayers;
  for(int i = 0; i < numOfPlayers;i++){
    players.push_back(Player(i+1));
  }
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


void Game::Round(){
   for(int i = 0; i< players.size();i++)
        players[i].resetCF();
   int index = 0;
   int maxBet = 0;
   while(!isPlayersCalled()){
     std::cout << "Players " << index+1 << " turn" << "You have " << players[index].getMoney() << std::endl;
     maxBet = players[index].Play(maxBet);
     index++;
     if(index >= players.size()){
       index = 0;
     }
   }
}
bool Game::isPlayersCalled(){
  for(int i = 0; i < players.size();i++){
    if(!players[i].getCalled())
        return false;
  }
  return true;
}
