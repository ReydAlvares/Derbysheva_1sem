#include <stdio.h>
#define N 1000

int main()
{
    int n = 0, k = 0, a[N], i = 0, t = 0;
    
    scanf("%d", &n);
    while(('\n' != scanf("%d", &a[i])) && (i < n-1))
    {
        i++;
    }
    scanf("%d", &k);
    
    for(t = 0; t <= i; t++)
    {
        if(k == a[t])
        {
            break;
        }
        else
        t = -1;
    }
    
    printf("%d", t);
    return 0;
}