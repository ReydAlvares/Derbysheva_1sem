#include <stdio.h>

float celsius(int f)
{
    return (5.00/9.00)*f - 160.00/9.00;
}

int main()
{
    int fa = 0;
    float cel = 0;

    scanf("%d", &fa);
    cel = celsius(fa);
    printf("%f", cel);

    return 0;
}