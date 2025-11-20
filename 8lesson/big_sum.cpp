#include <stdio.h>

#define N 100
// const int N = 100;
typedef struct {
    char a[N];       // number is a[0]*10^0 + a[1]*10^1 + ..+ a[n]*10^n
    unsigned int n;  // наибольшая степень десяти
} Decimal;

void elong_print(Decimal x);
Decimal add (Decimal x, Decimal y);
int main()
{
    Decimal x = {{9, 9, 9}, 2};  // set number 147
    Decimal y = {{1}, 0};     // set number 13
    Decimal res;

    res = add(x, y);             // res = x+y = 147+13 = 160
    elong_print(res);            // print 160

    return 0;
}

Decimal add (Decimal x, Decimal y)
{
    unsigned int sum_n_max = 0;
    Decimal      sum = {{0}, 0};

    if(x.n >= y.n)
    {
        sum_n_max = y.n;
        sum.n = x.n;
        for(unsigned i = x.n; i > x.n - y.n; i--)
        {
            sum.a[i] = x.a[i];
        }
    }
    else
    {
        sum_n_max = x.n;
        sum.n = y.n;
        for(unsigned i = x.n; i > y.n - x.n; i--)
        {
            sum.a[i] = y.a[i];
        }
    }
// size_t
    for(unsigned int i = 0; i <= sum_n_max; i++)
    {
        sum.a[i] += (char)((x.a[i] + y.a[i])%10);
        sum.a[i+1] += (char)((x.a[i] + y.a[i])/10);
    }

    if(sum.a[sum.n + 1] != 0)
    {
        (sum.n)++;
    }

    return sum;
}

void elong_print(Decimal x)
{
    for(int i = (int)x.n; i >= 0; i--)
    {
        printf("%d", x.a[i]);
    }
    printf("\n");

    return;
}