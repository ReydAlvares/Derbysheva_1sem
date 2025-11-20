#include <stdio.h>

#define ROWS 3
#define COLUMNS 3

int sum_row(int a[3][3], int irow);
int sum_col(int a[3][3], int icol);
int sum_diag(int a[3][3]);
int sum_diag2(int a[3][3]);
int magic_matrix(int a[ROWS][COLUMNS]);
int main()
{
    int a[ROWS][COLUMNS];

    for(int i = 0; i < ROWS; i++) 
    {
        for(int j = 0;  j < COLUMNS; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    
    printf("%s\n", magic_matrix(a) == 0? "MAGIC": "NO");
    
    return 0;
}

int magic_matrix(int a[ROWS][COLUMNS])
{
    int control_sum = sum_row(a, 0);

    for(int i = 1; i < ROWS; i++)
    {
        if(sum_row(a, i) != control_sum)
            return 1;
    }

    for(int i = 0; i < COLUMNS; i++)
    {
        if(sum_col(a, i) != control_sum)
            return 1;
    }

    if(sum_diag(a) != control_sum)
            return 1;

    if(sum_diag2(a) != control_sum)
            return 1;

    return 0;
}

int sum_row(int a[3][3], int irow)
{
    int sum = 0;
    for(int i = 0; i < 3; i++)
    {
        sum += a[irow][i];
    }
    return sum;
}

int sum_col(int a[3][3], int icol)
{
    int sum = 0;
    for(int i = 0; i < 3; i++)
    {
        sum += a[i][icol];
    }
    return sum;
}

int sum_diag(int a[3][3])
{
    int sum = 0;
    for(int i = 0, j = 0; i < 3 && j < 3; i++, j++)
    {
        sum += a[i][j];
    }
    return sum;
}

int sum_diag2(int a[3][3])
{
    int sum = 0;
    for(int i = 0, j = COLUMNS-1; i < ROWS && j >= 0; i++, j--)
    {
        sum += a[i][j];
    }
    return sum;
}
