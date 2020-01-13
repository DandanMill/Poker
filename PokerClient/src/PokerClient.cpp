#include "PokerClient.h"
#include <iostream>

PokerClient::PokerClient()
:player(id)
{
	Network::init(sock,server,"127.0.0.1");
	Network::initClient(sock,server);

	recv(sock,&id,sizeof(int),0);
	player = Player(id);

	Network::recvGameState(sock,g);

	g.d.printDeck();
		
}