#include <stdio.h>

int delim_konfety(int a);
int main()
{
    int konfet;
    scanf("%d", &konfet);

    int detey = delim_konfety(konfet);
    printf("детей - %d\n", detey);

    return 0;
}

int delim_konfety(int a)
{
    printf("a = %d\n", a);
    if(a == 1)
        return 1;
    int res =1 + delim_konfety(a - a/2);
    printf("a1 = %d\n", a);

    return res;
   
}