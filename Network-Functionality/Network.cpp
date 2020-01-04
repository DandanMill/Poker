#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <utility>


namespace Network{
    void init(int &sock,struct sockaddr_in &server,const char* ip){
        sock = socket(AF_INET,SOCK_STREAM,0);
        server.sin_family = AF_INET;
        server.sin_port = htons(8080);
        inet_pton(AF_INET,ip,&server.sin_addr);
    }
}
