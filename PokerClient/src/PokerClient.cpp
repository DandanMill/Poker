#include "PokerClient.h"
#include <iostream>

PokerClient::PokerClient()
:player(id)
{
	
	//Initialization-----------------------------
	Network::init(connection,server,"127.0.0.1");
	Network::initClient(connection,server);
	char exit = ' ';
	//Get Id--------------------------
	recv(connection,&id,sizeof(int),0);
	player = Player(id);
	//Get Cards------------------------
	Network::recvGameState(connection,g);
	std::cout << "You are player number: " << player.getId() << std::endl;
	g.d.showHand(player.getId());
	//Get Bets--------------------------
	while(exit != 'q'){
		Network::recvGameState(connection,g);
		player = g.players;
		g.maxBet = player.Play(g.maxBet);
		g.players = player;
		Network::sendGameState(connection,g);
		recv(connection,&exit,sizeof(exit),0);
	}
	//Second round of betting-----------
	exit = ' ';
	while(exit != 'q'){
		Network::recvGameState(connection,g);
		player = g.players;
		g.maxBet = player.Play(g.maxBet);
		g.players = player;
		Network::sendGameState(connection,g);
		recv(connection,&exit,sizeof(char),0);
	}
	std::cout << "bababoui babaoui" << std::endl;
	close(connection);
}