#include "Network.h"
#include "Player.h"
class PokerClient{
    
    public:
    PokerClient();
    const char* returnCard(int num);
    const char* returnSuit(int suit);
    void printDeck();
    void showHand();
    void Play();
    private:
    int sock, id = 0;
    sockaddr_in server;
    Network::PokerPacket p;
    Player player;
};
