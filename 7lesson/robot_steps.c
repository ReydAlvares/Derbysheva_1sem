#include <stdio.h>

int main()
{
    int s = 0, L = 0, i = 0, k = 0, dist = 0;

    scanf("%d%d%d", &s, &L, &k);

    if(L>s)
    {
        printf("%d %d\n", i, s);
    }
    else
    {
        dist = s;
        while(dist >= L)
        {
            dist -= L;
            i++;
            L += k;
        }
        printf("%d %d\n", i, dist);
    }

    return 0;
}