#include "Deck.h"
#include <iostream>

Deck::Deck()
{
  for(int i = 0; i  < 4; i++){
  	for(int j = 0; j < 13;j++){
		deck[i][j] = 0;	
    }
  }
}

void Deck::printDeck()
{
  for(int i = 0; i < 4; i++){
     for(int j = 0; j < 13;j++){
	     std::cout << deck[i][j];
     }
     std::cout << std::endl;
  }
}

void Deck::setCard(int num,int suit,int player)
{
   	if(deck[suit-1][num-1] == 0)
		deck[suit-1][num-1] = player;

	else
		std::cout << "This Card is already taken";
}

std::string Deck::returnSuit(int suit) {
	suit--;
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

std::string Deck::returnCard(int num) {
	num--;
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

void Deck::showHand(int player) {
	initializeHand(player);
	for (int i = 0; i < 5; i++) {
		std::cout << returnCard(cards[i].first) << " Of " << returnSuit(cards[i].second) << std::endl;
	}
}

void Deck::initializeHand(int player) {
	int index = 0;
	while (index < 5) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 13; j++) {
				if (deck[i][j] == player) {
					cards[index].first = j + 1;
					cards[index].second = i + 1;
					index++;
				}
			}
		}
	}
}

void Deck::checkHand(int player) {
	initializeHand(player);

}