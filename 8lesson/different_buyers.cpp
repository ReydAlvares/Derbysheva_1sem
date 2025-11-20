#include <stdio.h>
#define N 1000

int main()
{
    unsigned long long timestamp = 0, 
                       recept_id = 0;
    int id = 0,
        max_id = 0,
        count = 0,  
        n = 0, // n - количество покупок
        different_id[N] = {0}; 

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        scanf("%llu%d%llu", &timestamp, &id, &recept_id);
        (different_id[id-1])++;
        if(id > max_id)
        {
            max_id = id;
        }
    }
    for(int i = 0; i < max_id; i++)
    {
        if(different_id[i] != 0)
        {
            count++;
        }
    }

    printf("%d\n", count);
    return 0;
}