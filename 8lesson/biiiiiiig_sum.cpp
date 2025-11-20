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
    Decimal x = {{0, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 9, 8, 7, 6, 5, 4, 3, 2, 1}, 19};  // set number 147
    Decimal y = {{3, 2, 1, 0, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 9, 8, 7, 6, 5, 4, 3, 2, 1}, 22};     // set number 13
    Decimal res;

    res = add(x, y);             // res = x+y = 147+13 = 160
    elong_print(res);            // print 160

    return 0;
}

Decimal add (Decimal x, Decimal y)
{
    Decimal      sum = {{0}, 0};
    unsigned int min_n = 0;
    char         ost = 0;
    if(x.n >= y.n)
    {
        min_n = y.n;
        sum.n = x.n; 
    }
    else
    {
        min_n = x.n;
        sum.n = y.n; 
    }
    
    //printf("min n = %u\n-----------------------\n", min_n);

    for(unsigned int i = 0; i <= min_n; i++)
    {
        sum.a[i] = (char)((x.a[i] + y.a[i] + ost)%10);
        ost = (char)(((x.a[i] + y.a[i] + ost)/10));
        //printf("  i = %u,\nx1 = %d, y1 = %d,\nsum[%u] = %d, ost = %d\n", i, x.a[i], y.a[i], i, sum.a[i], ost);
    }
    
    //printf("-----------------------\n");

    for(unsigned int i = min_n + 1; i <= sum.n; i++)
    {
        if(x.n >= y.n)
        {
            sum.a[i] = (char)((x.a[i] + ost)%10);
            ost = (char)((x.a[i] + ost)/10);
            //printf("  i = %u,\nx1 = %d,\nsum[%u] = %d, ost = %d\n", i, x.a[i], i, sum.a[i], ost);
        }
        else
        {
            sum.a[i] = (char)((y.a[i] + ost)%10);
            ost = (char)((y.a[i] + ost)/10);
            //printf("  i = %u,\ny1 = %d,\nsum[%u] = %d, ost = %d\n", i, y.a[i], i, sum.a[i], ost);
        }       
    }

    if(ost != 0)
    {
        (sum.n)++;
        sum.a[sum.n] += ost;
    }

    return sum;
}

void elong_print(Decimal x)
{
    printf("%u: ", x.n);
    for(int i = (int)x.n; i >= 0; i--)
    {
        printf("%d", x.a[i]);
    }
    printf("\n");

    return;
}