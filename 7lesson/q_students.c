#include <stdio.h>

int main()
{
    int height = 0, temp = -2, c = 0, more_c = 0; //more_c is more 170
    while(temp != EOF && temp != 0)
    {
        if(temp = scanf("%d", &height) == 1)
        {
            c++;
        }
        else
            {
                break;
            }
        if(height > 170)
        {
            more_c++;
        }
        
    }
    printf("%d %d\n", c, more_c);
    
    return 0;
}