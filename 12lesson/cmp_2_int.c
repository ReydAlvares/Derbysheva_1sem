#include <stdio.h>
#include <string.h>

int cmp_int(const void * p1, const void * p2)
{
    long long x = *(int*)p1;
    long long y = *(int*)p2;

    printf("x = %lld, y = %lld\n", x, y);

    if(x > 0 && y < 0)
    {
        printf("1\n");
        return 1;
    }
    else if(x < 0 && y > 0)
    {
        printf("-1\n");
        return -1;
    }
    else
        return (int)(x-y);
}

int main()
{
    int x, y, res;
    scanf("%d%d", &x, &y);

    printf("%d\n", x);

    res = cmp_int(&x, &y);

    if (res < 0)
        res = '<';
    else if (res > 0)
        res = '>';
    else
        res = '=';

    printf("%c\n", res);

    return 0;
}