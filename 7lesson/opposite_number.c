#include <stdio.h>

int category(int x);
int main()
{
    int x = 0, y = 0;
    scanf("%d", &x);

    while(x != 0)
    {
        y *= 10;
        y += x%10;
        x /= 10;
    }

    printf("%d", y);

    return 0;
}

