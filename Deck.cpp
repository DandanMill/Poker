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
