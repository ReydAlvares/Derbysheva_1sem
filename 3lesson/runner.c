#include <stdio.h>
int main()
{
    int round = 0, total = 0;
    while(round == 0)
        scanf("%d%d", &round, &total);
    printf("%d %d", (int)(total/round), total%round);
    return 0;
}