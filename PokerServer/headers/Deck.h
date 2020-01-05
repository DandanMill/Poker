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
	void switchCard(int player,int num);
	void setRandomCard(int player);
	void dealCards(int player);
	void discardCard(int player,int card);


	void getState(int player,Network::PokerPacket &p);
	void initializeHand(int player,std::pair<int,int> hand[5],int d[4][13]);
	void showHand(int player,char *s[5]);
//	void initializeHand(int player);
	int checkHand(int player);
	private:
	int deck[4][13];
	std::pair <int, int> cards[5];
};


#endif
//const char* returnSuit(int suit);
//const char* returnCard(int num);