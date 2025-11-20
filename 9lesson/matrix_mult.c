#include <stdio.h>

void number_mult(int k, int rows, int cols, int a[10][10]);
int main()
{
    int n = 0, m = 0, k = 0;
    scanf("%d%d", &n, &m);

    int a[10][10] = {};
    for(int i = 0; i < n; i++) 
    {
        for(int j = 0;  j < m; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    scanf("%d", &k);

    number_mult(k, n, m, a);

    return 0;
}

void number_mult(int k, int rows, int cols, int a[10][10])
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            a[i][j] *= k;
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}