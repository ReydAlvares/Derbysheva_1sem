#include <stdio.h>

int main()
{
    int bell = 0, nbell = 0, n = 0;
    scanf("%d%d", &bell, &nbell);
    n = nbell - bell + 1;
    printf("%d", (((2*bell + (n-1)))*n)/2);

    return 0;
}