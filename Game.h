#ifndef GAME
#define GAME

#include "Deck.h"

class Game{

	public:
		Game();
		void editableMode();
		void dealCards(int player);
	private:
		Deck d;
};

#endif
