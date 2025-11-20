#include <stdio.h>
#define GENDER 1

int main()
{
    unsigned x;
    scanf("%x", &x);

    if((x & GENDER) == 1)
    {
        printf("%s\n", "ma");
    }
    if((x & GENDER) == 0)
    {
        printf("%s\n", "fe");
    }

    return 0;
}