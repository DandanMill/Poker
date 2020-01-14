#ifndef GAME
#define GAME

#include "Network.h"
#include <vector>

class Game{

	public:
		Game();
		void Playing();
		void dealCards();
		void getBets();
		bool checkCAndF();
		void switchCards();
		bool onlyPlayer(int i);
	private:
		std::vector<Player> players;
		std::vector<int> conns;
		int pot = 0;
		int sock;
		struct sockaddr_in server;
		Network::GameState g;

};

#endif
