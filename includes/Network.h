#pragma once
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/in.h>
#include <utility>

namespace Network{

struct PokerPacket{
        int deck[4][13];
        std::pair <int,int> hand[5];
        int maxBet;
        bool Round;
    };

void init(int &sock,struct sockaddr_in &server,const char* ip);
void sendPokerPacket(int &s,PokerPacket &p);
void recvPokerPacket(int &s, PokerPacket &p);
int initServer(int &sock,sockaddr_in &server);
void initClient(int &sock,sockaddr_in &server);



}
