#include "PokerClient.h"
#include <iostream>
PokerClient::PokerClient(){
    init(sock,server,"127.0.0.1");
    connect(sock,(sockaddr *)&server,sizeof(server));
    recv(sock,cards,1024*5,0);
    for(int i = 0; i < 5;i++){
    std::cout << cards[i] << std::endl;
    }

    close(sock);
}