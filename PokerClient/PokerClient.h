#include "Network.h"
#include <utility>

class PokerClient{
    
    public:
    PokerClient();
    const char* returnCard(int num);
    const char* returnSuit(int suit);
    
    private:
    int sock;
    sockaddr_in server;
    std::pair <int ,int> hand[5];    



};
