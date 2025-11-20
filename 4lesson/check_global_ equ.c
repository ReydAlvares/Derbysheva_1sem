#include <stdio.h>

int x;

void foo()
{
    x += 1;
}

int main()
{
    foo();
    foo();
    printf("%d", x);
    return 0;
}