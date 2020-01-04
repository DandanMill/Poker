#pragma once

#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/in.h>
#include <utility>

namespace Network{
void init(int&,struct sockaddr_in&,const char*);
struct PokerPacket{
        int deck[4][13];
        std::pair <int,int> hand[5];
    };
}
