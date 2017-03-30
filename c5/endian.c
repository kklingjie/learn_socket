#include <stdio.h>

void byteorder(){
    union {
        short value;
        char union_bytes[sizeof(short)];
    } test;
    test.value = 0x0102;
    
}
