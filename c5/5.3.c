#include <sys/socket.h>
#include <sys/types.h>

/**
 * [bind description]
 * @param  sockfd  [description]
 * @param  myaddr  通用sock地址
 * @param  addrlen [description]
 * @return         0 / -1 [EACCESS/EADDRINUSE]
 */
int bind(int sockfd, const struct sockaddr* myaddr, socklen_t addrlen);

int main(int argc, char const *argv[]) {
    return 0;
}
