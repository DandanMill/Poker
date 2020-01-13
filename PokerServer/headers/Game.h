#ifndef GAME
#define GAME

#include "Network.h"
#include <vector>

class Game{

	public:
		Game();
		void Playing();
		void dealCards();
	private:
		std::vector<int> players;
		int pot = 0;
		int sock;
		struct sockaddr_in server;
		Network::GameState g;

};

#endif
