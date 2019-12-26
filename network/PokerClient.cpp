#include "PokerClient.h"
#include <iostream>
PokerClient::PokerClient(){
    init(sock,server,"127.0.0.1");
    connect(sock,(sockaddr *)&server,sizeof(server));
    recv(sock,cards,100,0);
    std::cout << cards;
    
    close(sock);
}