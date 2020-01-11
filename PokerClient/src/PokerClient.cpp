#include "PokerClient.h"
#include <iostream>

PokerClient::PokerClient()
:player(id)
{
	Network::init(sock,server,"127.0.0.1");
	Network::initClient(sock,server);
	Play();
}

void PokerClient::Play(){
	
		std::cout << "Would you like to see your cards? ";
		std::cin.get();
		Network::recvGameState(sock,g);
		player = Player(g.id);
		showHand();
		Bet();
		Network::sendGameState(sock,g);
}

void PokerClient::Bet(){
	Network::recvGameState(sock,g);
	int bet = -1;
	while(bet < g.maxBet){
	std::cout << "Enter your bet: ";
	std::cin >> bet;
  }
    g.maxBet = bet;

}

void PokerClient::showHand(){
	std::cout << "You are Player Number: " <<  player.getId() << std::endl;
	for(int i = 0; i < 5;i++){
		std::cout << returnCard(g.hand[i].first) << " " << returnSuit(g.hand[i].second) << std::endl;
	}
}

void PokerClient::printDeck(){
	for(int i = 0; i < 4;i++){
		for(int j = 0; j < 13;j++){
			std::cout << g.deck[i][j];
		}
		std::cout << std::endl;
	}
}

const char* PokerClient::returnSuit(int suit) {

	switch (suit) {
	case 0:
		return "Hearts";
		break;
	case 1:
		return "Clubs";
		break;
	case 2:
		return "Diamonds";
		break;
	case 3:
		return "Spades";
		break;
	default:
		return "No suit";
		break;
	}
}

const char* PokerClient::returnCard(int num) {

	switch (num) {
	case 0:
		return "A";
		break;
	case 1:
		return "2";
		break;
	case 2:
		return "3";
		break;
	case 3:
		return "4";
		break;
	case 4:
		return "5";
		break;
	case 5:
		return "6";
		break;
	case 6:
		return "7";
		break;
	case 7:
		return "8";
		break;
	case 8:
		return "9";
		break;
	case 9:
		return "10";
		break;
	case 10:
		return "Jack";
		break;
	case 11:
		return "Queen";
		break;
	case 12:
		return "King";
		break;
	default:
		return "Not Num Card";
		break;
	}
}
