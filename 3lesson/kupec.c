#include <stdio.h>

int main()
{
    int rub = 0, kop = 0, rest = 0, n = 0;
    scanf("%d%d", &rub, &kop);

    while(rub*5 + rub > kop)
    {
        rub = rub - 1;
        kop += 100;
    }

    n = rub;
    rest = kop - (rub*5 + rub);

    printf("%d %d", n, rest);

    return 0;
}