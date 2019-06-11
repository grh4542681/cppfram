#include "sock_common.h"
#include "sock_address.h"
#include "sock_fd.h"
#include "sock_client.h"
#include <unistd.h>

int main()
{
    sock::SockFD* fd = NULL;
    std::string unixfile = "sock.sock";
//    sock::SockClient s = sock::SockClient(sock::SockFamily::TCP_LOCAL, unixfile.c_str());
    sock::SockClient s = sock::SockClient(sock::SockFamily::TCP_INET4, NULL, 60004);
//    sock::SockClient s = sock::SockClient(sock::SockFamily::TCP_INET6, NULL, 60004);
    fd = s.Connect();
    if(!fd){
        printf("------\n");
        return 0;
    }
    fd->Write("hello world", 12);
    fd->Close();
    return 0;
}
