#include <stdio.h>
#include <string.h>
#define N 1000

int main()
{
    int max_length = 0;
    char str[N] = {}, the_longest_str[N] = {};
    
    while(1 == scanf("%1000s", str))
    {
        int len = strlen(str);

        if(max_length < len)
        {
            max_length = len;
            strcpy(the_longest_str, str);
            printf("%s %d\n", the_longest_str, max_length);
        }
    }

    printf("%s %d\n", the_longest_str, max_length);

    return 0;
}