#include <stdio.h>

void byteorder(){
    union {
        short value;
        char union_bytes[sizeof(short)];
    } test;
    test.value = 0x0102;

    printf("%d\n", test.union_bytes[0] );
    printf("%d\n", test.union_bytes[1] );
}

int main(int argc, char const *argv[]) {
    byteorder();
    return 0;
}
