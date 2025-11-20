#include <stdio.h>

int main()
{
    int n = 0, day = 0;
    scanf("%d%d", &n, &day);
    printf("%d", ((int)((n - day)/7)+1));

    return 0;
}