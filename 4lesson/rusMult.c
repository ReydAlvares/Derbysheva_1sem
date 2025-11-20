#include <stdio.h>

int rusMult(int a, int b);

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d\n", rusMult(a, b));
    return 0;
}

int rusMult(int a, int b)
{
    int res = 0;
    if(b == 1)
    {
        res = a;
        printf("%d %d\n", a, b);
        printf("%d\n", a);
    }
    if (b>1)
    {
        printf("%d %d\n", a, b);
        if(b%2 == 0)
        {
            res = rusMult(2*a, b/2);
            printf("%d %d %d %d\n", res, a, 0, res);
        }
        else
        {
            res = a + rusMult(2*a, b/2);
            printf("%d %d %d %d\n", res - a, a, 1, res);
        }
    }
    return res;
}