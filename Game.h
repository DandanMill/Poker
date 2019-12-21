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
		int checkWon();
		void isPCalled(int maxBet);
		bool isCalled();
		int getAllBets();
	private:
		Deck d;
		std::vector<Player> players;
		int pot = 0;
};

#endif
