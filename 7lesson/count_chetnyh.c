#include <stdio.h>

int main()
{
    unsigned int n = 0;
    int temp = 0, count = 0;
    scanf("%u", &n);
    
    for( unsigned int i = 0; i < n; i++)
    {
        temp = 0;
        scanf("%d", &temp);
        if(temp%2 == 0)
        {
            count++;
        }
    }
    
    printf("%d\n", count);
    return 0;
}