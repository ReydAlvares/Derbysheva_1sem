#include <stdio.h>
#define N 67

int main()
{
    unsigned long long koeffs[N] = {0};
    int n = 0; // n - строка коэффициентов
    scanf("%d", &n);

    for(int i = 0; i <= n; i++)
    {
        if(i == 0)
        {
            koeffs[i] = 1;
        }
        else if(i == 1)
        {
            koeffs[i] = 1;
        }
        else
        {
            for(int j = i; j > 0; j--)
            {
                koeffs[j] += koeffs[j-1];
            }
        }
    }

    for(int i = 0; i <= n; i++)
    {
        printf("%llu ", koeffs[i]);
    }
    printf("\n");

    return 0;
}