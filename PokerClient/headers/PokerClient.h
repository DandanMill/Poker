#include "Network.h"
#include "Player.h"
#include <utility>

class PokerClient{
    
    public:
    PokerClient(int id);
    const char* returnCard(int num);
    const char* returnSuit(int suit);
    void printDeck();
    void showHand();
    private:
    int sock;
    sockaddr_in server;
    Network::PokerPacket p;
    Player player;
};
