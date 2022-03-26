#include "stdio.h"

unsigned char *p1=(unsigned char *)0x801000;
unsigned long *p2=(unsigned long *)0x801000;

void example(char ac[]) {
    printf("%d", sizeof(ac));
}

typedef struct {
    char t : 4;
    char k : 4;
    unsigned short v : 8;
    unsigned long m;
} ruijie_t;

// 32位机器
int main() {
    printf("%p %p\n", p1+5, p2+5);
    char ac[]="fdshjhfksdhfkjahsjfhkjsdhdfkjhskjhfkj";
    example(ac);
    printf("\n%d", sizeof(ruijie_t));
    return 0;
}