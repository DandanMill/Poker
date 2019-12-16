#include "Game.h"
#include <utility>
#include <iostream>

Game::Game(){

	d.setCard(1,1,1);
	d.setCard(2,1,1);
	d.setCard(3,1,1);
	d.setCard(4,1,1);
	d.setCard(1,1,1);
	//d.printDeck();
	d.showHand(1);
  std::cout << "\n\n\n" << d.checkHand(1).first << " " << d.checkHand(1).second << "\n";
}
