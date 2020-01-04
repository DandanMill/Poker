#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/in.h>

namespace Network{
void init(int&,struct sockaddr_in&,const char*);
}
