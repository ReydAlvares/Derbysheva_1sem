#include <stdio.h>

int fact(int n)
{
    if (n == 0)
    {
        printf("0! = 1\n");
        return 1;
    }

    int res = n * fact(n-1);
    printf("fact(%d) = %d\n", n, res);
    return res;

}

int main()
{
    int res = fact(5);
    printf("main: res = %d\n", res);
    return 0;
}