#include <stdio.h>

int main()
{
    int d = 0, k = 0, dk = 0, m = 0;
    scanf("%d%d", &d, &k);
    m = k;
    
    for(int i = 1; ;i++)
    {
        if(k%10 == k)
    {
            if(k == d)
            {
                dk++;
                break;
            }
            else
            {
                break;
            }
    }
        if(k%10 == d)
        {
            dk++;
            k /= 10;
            continue;
        }
        else if(k%10 != d)
        {
            k /= 10;
            continue;
        }
    }
    printf("%d %d %d\n", d, m, dk);
    return 0;
}