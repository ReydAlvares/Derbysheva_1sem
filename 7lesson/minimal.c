#include <stdio.h>

int main()
{
    unsigned int n = 0;
    int temp = 0;

    scanf("%u", &n);
    
    scanf("%d", &temp);
    printf("%d ", temp);

    int min = temp;
    for(unsigned int i = 0; i<n-1; i++)
    {
        temp = 0;
        scanf("%d", &temp);
        if(temp < min)
        {
            min = temp;
        }
        printf("%d", temp);

    }
    
    printf("\n%d", min);
    return 0;
}