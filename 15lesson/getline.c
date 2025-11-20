#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    size_t elements = 1;

    printf("Scanf elements: ");
    char * line = malloc(elements * sizeof(char));
    getline(&line, &elements, stdin);

    for(size_t i = 0; line[i] != '\n'; i++)
    {
        printf("%lu - %c\n", i+1, line[i]);

        int check = (int)line[i];
        switch(check)
        {
            case ')': printf("Goodbay\n"); 
            break;
            case '(': printf("Hello\n");
            break;
            default:
            break;
        }
    }

    free(line);

    return 0;
}