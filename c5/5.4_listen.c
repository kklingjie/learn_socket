#include <sys/socket.h>

/**
 * [listen description]
 * @param  sockfd  [description]
 * @param  backlog 监听队列长，完全连接的socket上限
 * @return         0 / -1
 */
int listen(int sockfd, int backlog);
