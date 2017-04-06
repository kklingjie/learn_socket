#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
// struct in_addr {
//     unsigned long int s_addr;
// };

//IP地址转换
int main(int argc, char const *argv[]) {
    long addr_str = inet_addr("1.2.3.4");
    printf("%ld\n",addr_str);

    //inet_aton
    // struct in_addr adr_inet;
    // inet_aton("1.3.4.5",&adr_inet);

    //inet_ntoa 不可重入
    struct in_addr addr1,addr2;
    ulong l1,l2;
    l1= inet_addr("192.168.0.74");
    l2 = inet_addr("211.100.21.179");
    memcpy(&addr1, &l1, 4);
    memcpy(&addr2, &l2, 4);

    printf("%s : %s\n", inet_ntoa(addr1), inet_ntoa(addr2)); //注意这一句的运行结果
    printf("%s\n", inet_ntoa(addr1));
    printf("%s\n", inet_ntoa(addr2));

    return 0;
}
