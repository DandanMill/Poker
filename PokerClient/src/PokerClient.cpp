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
	while(1){
	player.resetCF();
	player.setBet(0);
	g.players = player;
	Network::sendGameState(connection,g);
	char exit = ' ';
	//Get Cards------------------------
	Network::recvGameState(connection,g);
	std::cout << "You are player number: " << player.getId() << std::endl;
	g.d.showHand(player.getId());
	//Get Bets--------------------------
	while(exit != 'q'){
		recv(connection,&exit,sizeof(exit),0);
		if(exit != 'q'){
			if(player.getFolded() == false){
			Network::recvGameState(connection,g);
			if(g.onlyPlayer == false){
			player = g.players;
			g.maxBet = player.Play(g.maxBet);
			g.players = player;
			Network::sendGameState(connection,g);
			}
			else
			{
				player.setCalled(true);
				g.players = player;
				Network::sendGameState(connection,g);
			}
			}
			else{
				std::cout << "You are folded!" << std::endl;
			}
		}
	}
	//Switch cards-------------------------------------
	if(player.getFolded() == false){
		Network::recvGameState(connection,g);
		switchCards();
		Network::sendGameState(connection,g);
		g.d.showHand(player.getId());
	}




	std::cout << "Round 2" << std::endl;
	//Second round of betting-----------
	exit = ' ';
	while(exit != 'q'){
		recv(connection,&exit,sizeof(char),0);
		if(exit != 'q'){
			if(player.getFolded() == false){
			Network::recvGameState(connection,g);
			if(g.onlyPlayer == false){
				player = g.players;
				g.maxBet = player.Play(g.maxBet);
				g.players = player;
				Network::sendGameState(connection,g);
			}
			else{
				player = g.players;
				player.setCalled(true);
				g.players = player;
				Network::sendGameState(connection,g);
			}
			}
			else{
				std::cout << "You are folded!" << std::endl;
			}
		}
	}
	recv(connection,&exit,sizeof(exit),0);
	if(exit == 'w'){
		std::cout << "You Won!\nYou're hand value is " << g.d.checkHand(player.getId()) << std::endl;
	}
	else{
		std::cout << "You Lost:(\nYou're hand value is " << g.d.checkHand(player.getId()) << std::endl;
	}
  }
	close(connection);
}

void PokerClient::switchCards(){
	int num;
	std::cout << "How many cards would you like to switch? ";
	std::cin >> num;
	g.d.switchCard(player.getId(),num);
}