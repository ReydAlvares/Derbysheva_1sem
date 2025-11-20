#include <stdio.h>

long long int ipow(long long int a, unsigned int n, unsigned int * depth);
int main()
{
    long long int a = 0, n = 0;
    unsigned int d = 0;

    scanf("%lld%lld", &a, &n);
    long long int res = ipow(a, n, &d);
    printf("%lld %u", res, d);
    return 0;
}

long long int ipow(long long int a, unsigned int n, unsigned int * depth)
{
    *depth = 0;
    long long int res = 0;
    if(n == 0 || a == 1)
    {
        return 1;
    }
    if(n == 1)
    {
        (*depth)++;
        return a;
    }

    if(n%2 == 0 && n/2 != 1)
    {
        res = ipow(a, n/2, depth)*ipow(a, n/2, depth);
        (*depth)++;
        return res;
    }
    else if(n%2 == 0 && n/2 == 1)
    {
        (*depth) += 2;
        return a*a;
    }
    else
    {
        res = a*ipow(a, n-1, depth);
        (*depth)++;
        return res;
    }
}




