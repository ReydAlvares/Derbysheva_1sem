#include <stdio.h>

int main()
{
    int c = 0, dk = 0;
    char d;
    scanf("%c", &d);
    printf("%c ", d);

    while((c = getchar()) != EOF && c !='\n')
    {
        printf("%c", c);
        if(c == d)
        {
            dk++;
        }
    }
    printf(" %d\n", dk);
    return 0;
}