#include "../socketlib/common.h"

class PokerClient{
    
    public:
    PokerClient();
    
    
    private:
    int sock;
    sockaddr_in server;
    struct Packet{
    char cards[5][1024] = {{0}};
    int money;
    }msg;
    
    



};

