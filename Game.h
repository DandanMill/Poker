#ifndef GAME
#define GAME

#include "Deck.h"
#include "Player.h"
#include <vector>

class Game{

	public:
		Game();
		void Round();
		void Playing();
		void switchCards(int player);
		bool isPlayersCalled();
	private:
		Deck d;
		std::vector<Player> players;
};

#endif
