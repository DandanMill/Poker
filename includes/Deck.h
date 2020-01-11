#ifndef DECK
#define DECK

#include <string>
#include <utility>
#include <Network.h>

class Deck{
	public:
	Deck();
	void shuffleDeck();
	void printDeck();
	int setCard(int num,int suit,int player);
	void setDeck(int d[4][13]);
	void getDeck(int d[4][13]);
	void switchCard(int player,int num);
	void setRandomCard(int player);
	void dealCards(int player);
	void discardCard(int player,int card);
	const char* returnSuit(int suit);
	const char* returnCard(int num);
	void getState(int player,Network::GameState &g);
	void initializeHand(int player,std::pair<int,int> hand[5],int d[4][13]);
	void showHand(int player);
	void initializeHand(int player);
	int checkHand(int player);
	private:
	int id = 1;
	int deck[4][13];
	std::pair <int, int> cards[5];
};


#endif

