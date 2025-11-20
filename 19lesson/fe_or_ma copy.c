#include <stdio.h>
#define HAT 4

int main()
{
    unsigned x;
    scanf("%x", &x);

    printf("%s\n", (x & HAT) ? "ha" : "nh");
    
    return 0;
}