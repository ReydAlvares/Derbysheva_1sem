#include <stdio.h>

void print_bin(unsigned char x, char end);

int main()
{
    unsigned char x;
    scanf("%hhu", &x);      // hh используеся для указания, что работа с char

    print_bin(x, '\n');     // напечатать х и в конце напечатать \n

    return 0;
}

void print_bin(unsigned char x, char end)
{
    unsigned char bin[8] = {0};

    for(int i = 0; i < 8; i++)
    {
        bin[i] = x%2;
        x /= 2;

        if(x == 1)
        {
            bin[i+1] = 1;
            break;
        }
    }

    for(int i = 7; i >= 0; i--)
    {
        printf("%d", bin[i]);
    }

    printf("%c", end);
}