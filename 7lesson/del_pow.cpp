#include <stdio.h>
#include <math.h>

int main()
{
    int n = 0, k = 0, del = 1, i = 2;
    scanf("%d%d", &n, &k);

    while(n != 1)
    {
        int p = pow(i, k);
        if(n%p == 0)
        {
            printf("%d %d\n", i, n/p);
            del *= i;
            n /= p;
            continue;
        }
        else if(n%p != 0 && n >= p)
        {
            i++;
            continue;
        }
        else
        {
            printf("-1\n");
            break;
        }
            
    }

    if(n == 1)
    printf("%d\n", del);
    
    return 0;
}