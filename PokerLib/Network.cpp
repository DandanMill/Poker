#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <utility>
#include "Network.h"


namespace Network{
    
    void init(int &sock,struct sockaddr_in &server,const char* ip){
        sock = socket(AF_INET,SOCK_STREAM,0);
        server.sin_family = AF_INET;
        server.sin_port = htons(8080);
        inet_pton(AF_INET,ip,&server.sin_addr);
    }    
    void sendGameState(int &s,Network::GameState &g)
    {
        send(s,&g,sizeof(g),0);
    }
    void recvGameState(int &s,Network::GameState &g){
        recv(s,&g,sizeof(g),0);
    }

    int initServer(int &sock,sockaddr_in &server){
        bind(sock,(sockaddr *)&server,sizeof(server));
        listen(sock,3);
        int conn = accept(sock,nullptr,nullptr);
        return conn;   
    }
    void initClient(int &sock,sockaddr_in &server){
        connect(sock,(sockaddr *)&server,sizeof(server));
    }


}