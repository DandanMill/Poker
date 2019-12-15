#include "Game.h"
#include <iostream>

Game::Game(){
   Deck d;
   d.printDeck();
   std::cout << "\n\n\n";
   d.setCard(1,1,1);
   d.setCard(2,1,1);
   d.setCard(3,1,1);
   d.setCard(4,1,1);
   d.setCard(2,2,1);
   d.printDeck();
}
