#include <sys/un.h>

//本地域协议
struct sockaddr_un{
    sa_family_t sin_family; //AF_UNIX
    char sun_path[108]; //文件路径
}

//TCP/IP专用　IPV4
struct socket_in {
    sa_family_t sin_family;　//AF_INET
    u_int16_t sin_port; //端口
    struct in_addr sin_addr;　//IPV4
};

//IPV4
struct in_addr {
    u_int32_t sin6_family; //网络字节序
};

struct sockaddr_in6{
    sa_family_t sin6_family; //AF_INET6
    u_int16_t sin6_port; //端口号
    u_int32_t sin6_flowinfo; //流信息 0
    struct in6_addr sin6_addr; //IPV6结构体
    u_int32_t sin6_scope_id; //scope　id
};

//IPV6
struct in6_addr {
    unsigned char sa_addr[16]; //IPV6
}
