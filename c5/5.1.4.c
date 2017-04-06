#include <arpa/inet.h>
#include <stdio.h>

// struct in_addr {
//     unsigned long int s_addr;
// };

//IP地址转换
int main(int argc, char const *argv[]) {
    long addr_str = inet_addr("1.2.3.4");
    printf("%ld",addr_str);

    //inet_aton
    // struct in_addr adr_inet;
    // inet_aton("1.3.4.5",&adr_inet);

    //inet_ntoa 不可重入
    struct in_addr addr1,addr2;
    unsigned long l1,l2;

    char l1 = inet_addr("1.2.3.4");
    char l2 = inet_addr("3.5.6.7");

    memcpy(&addr1,&l1,4);
    memcpy(&addr2,&l2,4);

    printf("sz1:%s\n", inet_ntoa(addr1));
    printf("sz2:%s\n", inet_ntoa(addr2));

    return 0;
}
