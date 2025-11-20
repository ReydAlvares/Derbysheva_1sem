#include <stdio.h>
#include <string.h>

#define N 100
typedef struct {
    char a[N];       // number is a[0]*10^0 + a[1]*10^1 + ..+ a[n]*10^n
    unsigned int n;  // наибольшая степень десяти
}Decimal;

void elong_set (Decimal * res, const char str[ ])
{
    //printf("%d %d - int, %c - char\n", str[0], str[0], str[0]);
    res -> n = strlen(str) - 1;
    for(int i = (res -> n), j = 0; i >= 0, j <= (res -> n); i--, j++)
    {
        res -> a[i] = str[j] - '0';
        //printf("res.a[%d] - %d, str[%d] = %d, \n", i, res -> a[i], j, str[j]);
    }
    return;
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