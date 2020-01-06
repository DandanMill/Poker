#pragma once
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/in.h>
#include <utility>

namespace Network{

struct GameState{
        int deck[4][13];
        std::pair <int,int> hand[5];
        int maxBet;
        bool called;
    };

void init(int &sock,struct sockaddr_in &server,const char* ip);
void sendGameState(int &s,GameState &g);
void recvGameState(int &s, GameState &g);
int initServer(int &sock,sockaddr_in &server);
void initClient(int &sock,sockaddr_in &server);



}
