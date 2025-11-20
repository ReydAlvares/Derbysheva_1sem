#include <stdio.h>

int main()
{
    unsigned x;
    scanf("%o", &x);

    for(int i = 0; i < 3; i++)
    {
        printf("%c", x & 256 ? 'r' : '-');
        printf("%c", x & 128 ? 'w' : '-');
        printf("%c", x & 64 ? 'x' : '-');
        x <<= 3;
    }
    printf("\n");

    return 0;
}