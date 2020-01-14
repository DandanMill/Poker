#include "PokerClient.h"
#include <iostream>

PokerClient::PokerClient()
:player(id)
{
	//Initialization-----------------------------
	Network::init(connection,server,"127.0.0.1");
	Network::initClient(connection,server);
	//Get Id--------------------------
	recv(connection,&id,sizeof(int),0);
	player = Player(id);
	//Get Cards------------------------
	Network::recvGameState(connection,g);
	std::cout << "You are player number: " << player.getId() << std::endl;
	g.d.showHand(player.getId());
	//Get Bets--------------------------
	Network::recvGameState(connection,g);
	g.maxBet = player.Play(g.maxBet);
	g.players = player;
	Network::sendGameState(connection,g);
	//Second round of betting-----------
	player.setCalled(false);
	Network::recvGameState(connection,g);
	g.maxBet = player.Play(g.maxBet);
	g.players = player;
	Network::sendGameState(connection,g);
	close(connection);
}