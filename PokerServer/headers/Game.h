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
		bool checkCalled();
		
	private:
		std::vector<Player> players;
		std::vector<int> conns;
		int pot = 0;
		int sock;
		struct sockaddr_in server;
		Network::GameState g;

};

#endif
