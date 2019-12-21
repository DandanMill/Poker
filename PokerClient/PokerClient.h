#include "../Game.h"
#include "../socketlib/common.h"

class PokerClient{

    public:
      PokerClient();

    private:
    int id;
    int sock;
    struct sockaddr_in server;

};