#include "Game.h"
#include <utility>
#include <iostream>
#include <ctime>
#include <cstdlib>
//ToDo: Make Editable Mode

Game::Game(){
      int option = 0;
      std::cout << "Hi Welcome to the Poker Game\n1: Play\n2: Make Editable Mode\n";
      std::cin >> option;
      switch(option){
        case 1:
          //There will be code here(duh!)
          break;
        case 2:
          editableMode();
          break;
        default:
          break;

      }

}

void Game::editableMode(){
  std::cout << "\n\n\n\n\n\n\n\n\n\n\n" << "Welcome to the editable mode!\n";
}
