#include "PokerClient.h"
#include <iostream>
PokerClient::PokerClient(){
    init(sock,server,"127.0.0.1");
    connect(sock,(sockaddr *)&server,sizeof(server));
    
    recv(sock,hand,sizeof(int) * 10,0);
	for(int i = 0; i < 5;i++){
		std::cout << returnCard(hand[i].first) << " " << returnSuit(hand[i].second) << std::endl;
	}
    close(sock);
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
