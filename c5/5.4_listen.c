#include <sys/socket.h>
#include <netinet/in.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>

static bool stop = false;

/**
 * [listen description]
 * @param  sockfd  [description]
 * @param  backlog 监听队列长，完全连接的socket上限
 * @return         0 / -1
 */
int listen_mine(int sockfd, int backlog);

static void handle_term (int sig){
    stop = true;
}

int main(int argc, char const *argv[]) {
    //kill -l 查看信号
    // SIGTERM 是进程终止的信号,如果进程不能中断，那么会忽略SIGTERM信号
    // SIGKILL则会强制停止
    signal(SIGTERM,handle_term);

    if (argc <= 3) {
        printf("useage: %s ip_address port_number backlog\n", basename(argv[0]));
        return 1;
    }

    const char* ip = argv[1];
    //atoi:ascii to integer
    // "1234" => 1234
    int port = atoi(argv[2]);
    int backlgo = atoi(argv[3]);

    int sock = socket(PF_INET, SOCK_STRAM, 0);
    //如果为false, stderr打印错误信息, abort终止程序
    assert(sock >= 0 );

    struct sockaddr_in address;
    //推荐使用memset memset(&address, 0, sizeof(address));
    bzero(&address, sizeof(address));
    address.sin_family = AF_INET;
    //点分十 > 二进制
    inet_pton(AF_INET, ip, &address.sin_addr);
    //调整字节序 host to network sequence
    address.sin_port = htons(port);

    int ret = bind(sock, (struct sockaddr*)&address, sizeof(address));
    assert(ret != -1);

    while (!stop) {
        sleep(1);
    }

    close(sock);

    return 0;
}
