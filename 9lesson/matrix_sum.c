#include <stdio.h>

void sum(int rows, int cols, int a[10][10], int b[10][10], int c[10][10]);
void vvod(int a[][10], int rows, int col);
int main()
{
    int n = 0, m = 0;
    scanf("%d%d", &n, &m);

    int a[10][10] = {0}, b[10][10] = {0}, c[10][10] = {0};
    vvod(a, n, m);
    vvod(b, n, m);

    sum(n, m, a, b, c);

    return 0;
}


void sum(int rows, int cols, int a[10][10], int b[10][10], int c[10][10])
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            c[i][j] = a[i][j] + b[i][j];
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
}

void vvod(int a[][10], int rows, int col)
{
   for(int i = 0; i < rows; i++) 
    {
        for(int j = 0;  j < col; j++)
        {
            scanf("%d", &a[i][j]);
        }
    } 
}