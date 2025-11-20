#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define N 1000

int main()
{
    char str[N] = {};
    int counter = 0;
    while(scanf("%1000s", str) == 1)
    {
        //printf("string - %s\n", str);
        char *p = strstr(str, "bomb");

        //printf("adress bomb - %p\n", p);

        for(size_t i = 1; i < strlen(str); i++)
        {
            if(p != NULL)
            {
                counter++;

                //printf("Added +1 to %d, now is %d\n", counter - 1, counter);

                p = strstr(p + 4 * i, "bomb");

                //printf("adress bomb in string - %p\n", p);

                continue;
            }

            //printf("No more\n");
            break;
        }
    }
    printf("%d\n", counter);
       
    return 0;
}