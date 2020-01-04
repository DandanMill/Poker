#include "Network.h"
#include <utility>

class PokerClient{
    
    public:
    PokerClient();
    const char* returnCard(int num);
    const char* returnSuit(int suit);
    void printDeck();
    private:
    int sock;
    sockaddr_in server;
    Network::PokerPacket p;

};
