#include <stdio.h>
#define N 1300001

void simple(char*);
int main()
{
    int n = 0; // n - количество чисел
    unsigned long for_check;
    char prime[N] = {0};

    simple(prime);

    scanf("%d", &n);
    for(int k = 0; k < n; k++)
    {
        scanf("%lu", &for_check);
        if(prime[for_check] == 0)
        {
            printf("%lu ", for_check);
        }
    }
    printf("\n");
    return 0;
}

void simple(char* prime)
{

    for(int i = 2; i < N; i++)
    {
        if(prime[i] != 0)
            continue;
        
        unsigned count_changes = 0;
        for(int j = i+i; j < N; j+=i)
        {
            if(prime[j] != 0)
                continue;
            prime[j] = 1;
            count_changes++;
        }
        if(count_changes == 0)
        {
            break;
        }

    }
}