#include <stdio.h>
#include <string.h>

#define N 100
typedef struct {
    char a[N];       // number is a[0]*10^0 + a[1]*10^1 + ..+ a[n]*10^n
    unsigned int n;  // наибольшая степень десяти
}Decimal;

void elong_set (Decimal * res, const char str[ ])
{
    (res -> n) = strlen(str);
    //printf("len - %u\n", (res -> n));
    for(int i = (res -> n); i <= 0; i--)
    {
        printf("str[%u] - %c\n", i, str[i]);
        res -> a[i] = str[i];
        printf("res.a[%u] - %c\n res.n = %u\n", i, res->a[i], res -> n);
        printf("--------------------\n");
    }
}

void elong_print(Decimal x)
{
    for(int i = x.n; i >= 0; i--)
        {
            printf("i - %d, res[%d] - %d\n", i, i, x.a[i]);
        }
    printf("\n");
    return;
}

int main()
{
    Decimal res;
    elong_set(&res, "12345678901234567890");  // res = 12345678901234567890

    elong_print(res);                         // print 12345678901234567890

    return 0;
}

