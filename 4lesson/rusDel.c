#include <stdio.h>

int rusDel(int a, int b);
int main()
{
    int a = 0, b = 0;
    scanf("%d%d", &a, &b);
    printf("%d\n", rusDel(a, b));
    return 0;
}

int rusDel(int a, int b)
{
    int mult = 0, rem = 0, part = 0, k = 0;
    if(a == 1 || a <= b)
    {
        printf("%d\n", 1);
        return 1;
    }
    else if(a > b && a%2 == 0)
    {
        mult = 2;
        printf("%d %d %d\n", a/2, 2, 0);
        k = rusDel(a/2, b);
        part = k * mult;
        printf("%d * %d + %d = %d\n", k, mult, rem, part);
    }
    else if(a > b && a%2 == 1)
    {
        mult = 1;
        rem = 1;
        printf("%d %d %d \n", a-b, 1, 1);
        k = rusDel(a, b);
        part = k + rem;
        printf("%d * %d + %d = %d \n", k, mult, rem, part);
    }
    
    return part;
}