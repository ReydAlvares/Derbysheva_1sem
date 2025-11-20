#include <stdio.h>

#define ROWS 9 
#define COLUMNS 9

int check_rows(int sudoku[][COLUMNS])
{
    for(int i = 0; i < ROWS; i++)
    {
        int numbers[COLUMNS] = {0};
        for(int j = 0; j < COLUMNS; j++)
        {
            if((numbers[sudoku[i][j] - 1])++ > 1)
            {
                printf("ROW %d %d sudoku[i][j]=%d %d\n", i, j, sudoku[i][j], numbers[sudoku[i][j] - 1]);
                return 1;
            }
        }
    }
    return 0;
}

int check_cols(int sudoku[][COLUMNS])
{
    
    for(int i = 0; i < COLUMNS; i++)
    {
        int numbers[ROWS] = {0};
        for(int j = 0; j < ROWS; j++)
        {
            if((numbers[sudoku[j][i] - 1])++ > 1)
            {
                printf("COL %d %d\n", i, j);
                return 1;
            }
        }
    }
    return 0;
}

int check_one_square(int sudoku[][COLUMNS], int start_i, int start_j)
{
    int numbers[ROWS] = {0};
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            //printf("sudoku[%d][%d] = %d, count_sudoku_number = %d\n", i+start_i, j+start_j, numbers[sudoku[i+start_i][j+start_j] - 1] + 1);
            if(++(numbers[sudoku[i+start_i][j+start_j] - 1]) != 1)
            {
                //printf("SQ %d %d\n", i, j);
                return 1;
            }
        }
    }
    return 0;
}

int check_square(int sudoku[][COLUMNS])
{
    //printf("Enter\n");
    for(int sq_i = 0; sq_i < COLUMNS; sq_i +=3)
    {
        for(int sq_j = 0; sq_j < COLUMNS; sq_j +=3)
        {
            if(check_one_square(sudoku, sq_i, sq_j) == 1)
                return 1;
        }
    }
    return 0;
}

int right_sudoku(int sudoku[][COLUMNS])
{
    if(check_rows(sudoku) == 1 || check_cols(sudoku) == 1 || check_square(sudoku) == 1)
        return 1;
    return 0;
}

int main()
{
    int sudoku[ROWS][COLUMNS] = {0};
    for(int i = 0; i < ROWS; i++) 
    {
        for(int j = 0;  j < COLUMNS; j++)
        {
            scanf("%d", &sudoku[i][j]);
        }
    }
    printf("%s\n", right_sudoku(sudoku) == 0? "YES": "NO");
    return 0;
}