#ifndef DECK
#define DECK

class Deck{
	public:
	Deck();
	void printDeck();
	void setCard(int num,int suit,int player);
	int getCard(int num,int suit);
	private:
	int deck[4][13];

};


#endif
