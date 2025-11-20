#include <stdio.h>

void print_revers(int x);
int main()
{
    int x = 0, k = 0;
    scanf("%d", &x);
    print_revers(x);

    return 0;
}

void print_revers(int x)
{
    int p = 0;
    p = (x%10)*100000 + (x%100 - x%10)*1000 + (x%1000 - x%100)*10 + (x%10000 - x%1000)/10 + (x%100000 - x%10000)/1000 + (x%1000000 - x%100000)/100000;
    printf("%d", p);
}