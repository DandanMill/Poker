#pragma once
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <vector>
#include <unistd.h>
#include <netinet/in.h>
#include <utility>
#include <Player.h>
#include <Deck.h>

namespace Network{

struct GameState{
        Deck d;
        std::pair <int,int> hand[5];
        int maxBet = 0;
        Player players;
        int bet = 0;
        int id = 0;
};

void init(int &sock,struct sockaddr_in &server,const char* ip);
void sendGameState(int &s,GameState &g);
void recvGameState(int &s, GameState &g);
void initServer(int &sock,sockaddr_in &server,std::vector<int> &conns);
void initClient(int &sock,sockaddr_in &server);



}
