#include <stdio.h>

int main()
{
    int g1 = 0, s1 = 0, k1 = 0;
    int g2 = 0, s2 = 0, k2 = 0;
    scanf("%d%d%d%d%d%d", &g1, &s1, &k1, &g2, &s2, &k2);
    int g0 = g1 + g2, s0 = s1 + s2, k0 = k1 + k2;
    while(s0 >= 17 || k0 >= 29)
    {
        g0 += (int)(s0/17);
        s0 = s0%17;
        s0 += (int)(k0/29);
        k0 = k0%29;
    }
    printf("%d %d %d", g0, s0, k0);

    return 0;
}