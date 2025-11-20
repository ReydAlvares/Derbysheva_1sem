#include <stdio.h>
#define HAT_MASK 3

int main()
{
    unsigned x;
    scanf("%x", &x);

    switch(x >> 4 & HAT_MASK)
    {
        case 0x1: printf("rd\n"); break;
        case 0x2: printf("bw\n"); break;
        case 0x3: printf("bk\n"); break;
        default: printf("bn\n");
    }

    return 0;
}