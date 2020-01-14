#include "Network.h"
#include "Deck.h"
#include "Player.h"

class PokerClient{
    
    public:
    PokerClient();
    const char* returnCard(int num);
    const char* returnSuit(int suit);
    void printDeck();
    void showHand();
    void Bet();
    void Play();
    private:
    int connection, id = 0;
    Deck d;
    sockaddr_in server;
    Network::GameState g;
    Player player;
};
