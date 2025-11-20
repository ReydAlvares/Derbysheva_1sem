#include <stdio.h>
#include <string.h>

int main()
{
    char duration[10] = {};
    int step = 0, x = 0, y = 0;

    while(1)
    {
        scanf("%10s", duration);
        if(strcmp(duration, "Treasure!") == 0)
        {
            break;
        }
        scanf("%d", &step);
        
        if(strcmp("North", duration) == 0)
        {
            y += step;
            printf("y = %d + %d = %d\n", y-step, step, y);
        }
        if(strcmp("South", duration) == 0)
        {
            y -= step;
            printf("y = %d - %d = %d\n", y + step, step, y);
        }
        if(strcmp("East", duration) == 0)
        {
            x -= step;
            printf("x = %d - %d = %d\n", x+step, step, x);
        }
        if(strcmp("West", duration) == 0)
        {
            x += step;
            printf("x = %d + %d = %d\n", x-step, step, x);
        }
    }
    printf("%d %d\n", x, y);
    return 0;
}