#include "../socketlib/common.h"
#include <string>
class PokerClient{
    
    public:
    PokerClient();
    
    
    private:
    int sock;
    sockaddr_in server;
    char cards[5][1024] = {{' '}};
    
    



};

