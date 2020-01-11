#pragma once
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <vector>
#include <unistd.h>
#include <netinet/in.h>
#include <utility>

namespace Network{

struct GameState{
        int deck[4][13];
        std::pair <int,int> hand[5];
        int maxBet;
        bool called;
        bool folded;
        int bet;
        int id;
};

void init(int &sock,struct sockaddr_in &server,const char* ip);
void sendGameState(int &s,GameState &g);
void recvGameState(int &s, GameState &g);
void initServer(int &sock,sockaddr_in &server,std::vector<int> &conns);
void initClient(int &sock,sockaddr_in &server);



}
