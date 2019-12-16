#include "Game.h"
#include <utility>
#include <iostream>
//ToDo: Make Editable Mode

Game::Game(){
  int option = -1;
  while(option != 0){
    d.dealCards(1);
    d.showHand(1);
    std::cout << "\n\n";
    std::cin >> option;
  }
}

void Game::editableMode(){
  std::cout << "\n\n\n\n\n\n\n\n\n\n\n" << "Welcome to the editable mode!\n";
}
