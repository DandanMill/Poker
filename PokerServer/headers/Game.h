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
		void dealCards();
		void getBets();
	private:
		Deck d;
		std::vector<int> players;
		int pot = 0;
		int sock;
		struct sockaddr_in server;
		Network::GameState g;

};

#endif
