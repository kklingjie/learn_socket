#include <stdio.h>
#include <sys/socket.h>

//旧通用socket
struct sockaddr_fancivez {
    sa_family_t sa_family;
    char sa_data[14];
};

//不声明会报 ‘__ss_align’ undeclared here (not in a function)
unsigned long int __ss_align;

//新通用socket,内存对齐
struct sockaddr_storage_fancivez {
    sa_family_t sa_family;
    unsigned long int __ss_align;
    char __ss_padding[128-sizeof(__ss_align)];
};

int main(int argc, char const *argv[]) {
    printf("hello world！");
    return 0;
}
