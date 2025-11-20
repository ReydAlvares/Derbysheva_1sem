#include <stdio.h>
#define N 1000
int main()
{
    int n = 0;
    int b[10] = {}; //массив количества шаров

    scanf("%d", &n);
    int a[n];

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        b[a[i]]++;
    }
    for(int i = 0; i < 10; i++)
        printf("%d %d\n", i, b[i]);

    return 0;
}