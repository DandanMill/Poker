#ifndef DECK
#define DECK

#include <string>
#include <utility>

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
	std::string returnSuit(int suit);
	std::string returnCard(int num);
	void showHand(int player,std::string &s,int num);
	void initializeHand(int player);
	int checkHand(int player);
	private:
	int deck[4][13];
	std::pair <int, int> cards[5];
};


#endif
