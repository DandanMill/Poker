#include "Game.h"
#include <utility>
#include <iostream>

Game::Game(){
  int numOfPlayers = 0;
  std::cout << "Enter num of players: ";
  std::cin >> numOfPlayers;
  players.resize(numOfPlayers);
  Round();
}

void Game::Round(){

}
