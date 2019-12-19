#include "Deck.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

Deck::Deck(){
  shuffleDeck();
}

void Deck::shuffleDeck(){
  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 13; j++){
      deck[i][j] = 0;
    }
  }
}

void Deck::printDeck(){
  for(int i = 0; i < 4; i++){
     for(int j = 0; j < 13;j++){
	     std::cout << deck[i][j];
     }
     std::cout << std::endl;
  }
}


void Deck::discardCard(int player,int card){
    deck[cards[card].second][cards[card].first] = -1;
}

void Deck::switchCard(int player,int num){
   if(num > 0){
   int switchNum[num] = { 0 };
   std::cout << "Which cards would you like to switch? ";
   for(int i = 0; i < num ; i++){
     std::cin >> switchNum[i];
   }
   initializeHand(player);
   for(int i = 0; i < num; i++){
     discardCard(player,switchNum[i]-1);
     setRandomCard(player);
   }
  }
}

int Deck::setCard(int num,int suit,int player){
    if(deck[suit-1][num-1] == 0){
		deck[suit-1][num-1] = player;
    return 0;
  }
	else
		return -1;
}

void Deck::setRandomCard(int player){
  bool set = false;
  while(!set){
    if(setCard(rand() % 13 + 1, rand() % 4 + 1,player) == 0){
        set = true;
    }
  }
}

void Deck::dealCards(int player){
  srand(time(NULL));
  for(int i = 0; i< 5;i++){
    setRandomCard(player);
  }
}




std::string Deck::returnSuit(int suit) {

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
		for (int i = 0; i < 13; i++) {
			for (int j = 0; j < 4; j++) {
				if (deck[j][i] == player) {
					cards[index].first = i;
					cards[index].second = j;
					index++;

			}
		}
	}
		if (index < 5) {
			std::cout << "Error: Not enough cards dealt\n" << "exiting the program\n";
			exit(-1);
	}

}

int Deck::checkHand(int player) {

  initializeHand(player);
  int cardCount = 0;
  int suitCount = 0;
  //Check for num of cards
  int numOfCards[13] = {0};
  bool visited[13] = {false};
  for(int i = 0; i < 5; i++){
      if(visited[cards[i].first] == true){
        continue;
      }
      visited[cards[i].first] = true;
      for(int j = i+1; j < 5;j++){
        if(cards[i].first == cards[j].first){
            numOfCards[cards[i].first]++;
          }
      }
  }
  for(int i = 0; i < 13; i++){
    if(numOfCards[i] > 0)
      numOfCards[i]++;
    if(numOfCards[i] == 4){
      cardCount += 8;
    }else
    cardCount += numOfCards[i];
  }
  //Check for num of Suits
  int numOfSuits[4] = {0};
  for(int i = 0; i< 13;i++){
    visited[i] = false;
  }
  for(int i = 0; i< 5;i++){
    if(visited[cards[i].second] == true){
      continue;
    }
    visited[cards[i].second] = true;
    for(int j = i+1; j< 5;j++){
      if(cards[i].second == cards[j].second){
        numOfSuits[cards[i].second]++;
      }
    }
  }

  //Checked for num of cards
  //Checked for num of suits
  for(int i = 0; i < 4;i++){
    if(numOfSuits[i] > 0)
      numOfSuits[i]++;
      if(numOfSuits[i] == 5){
        suitCount = 5;
      }else{
        suitCount = 0;
      }
    }

  //checks for full house
  if(cardCount == 5){
    cardCount = 7;
  }

  //checks for straight
  if(cardCount == 0){
    for(int i = 1; i < 5; i++){
      if(cards[i].first - cards[i-1].first == 1){
        cardCount = 5;
      }
      else{
        cardCount = 0;
        break;
      }
    }
  }
  if(suitCount == 5 && cardCount == 5){
    cardCount = 10;
  }
  else if(suitCount == 5 && cardCount > 5){

  }
  else if(suitCount == 5 && cardCount <= 5){
    cardCount = 6;
  }



    return cardCount;
}
