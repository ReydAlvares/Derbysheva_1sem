#include <stdio.h>

void simpleFactors(unsigned int a, unsigned int last, unsigned int n);
void printFactor(unsigned int last, unsigned int n);
int main()
{
    unsigned int a = 0;
    scanf("%u", &a);
    simpleFactors(a, 2, 0);
    return 0;
}

void simpleFactors(unsigned int a, unsigned int last, unsigned int n)
{
    if (last <= a)
    {
        if(a%last == 0)
        {
            n++;
            simpleFactors(a/last,last, n);
           // printf("%d, %d, %d\n", a, last, n);
        }
        else
        { 
            simpleFactors(a,last+1, 0);
            printFactor(last, n);
        }
    }
    if(a == 1)
        printFactor(last, n);
}



void printFactor(unsigned int last, unsigned int n)
{
    if(n == 1)
        printf("%u ", last);
    else if(n>1)
        printf("%u^%u ", last, n);
}