#include <stdio.h>
#include <stdlib.h>

void arr_input(int * arr, int size)
{
    for(int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
}

/*int* answer_input()
{
    printf("Enter count: ");
    int count = 0;
    scanf("%d", &count);

    printf("Enter answer: ");
    int* answer = malloc(count*sizeof(int));
    arr_input(answer, count);

    return answer;
}*/

void arr_print(int * arr, int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int cmp_wa(const void * p1, const void * p2)
{
    int a = *(int*)p1;
    int b = *(int*)p2;

    return (a > b) - (a < b);
}

int main()
{
    /*int cont = 0;
    printf("Begin? (0 -no): ");
    scanf("%d", &cont);

    while(cont > 0)
    {*/
        //printf("size = ");
        int size = 0;
        scanf("%d", &size);

        //printf("array = \n");
        int * array = malloc(size*sizeof(int));
        arr_input(array, size);

        //int* answer = answer_input();

        int even_numbers_length = 1;
        int * even_numbers = malloc(even_numbers_length * sizeof(int));
        int * result = malloc(size*sizeof(int));

        for(int i = 0; i < size; i++)
        {
            if(array[i]%2 == 0)
            {
                result[i] = 0;
                even_numbers[even_numbers_length - 1] = array[i];
                even_numbers_length++;
                even_numbers = realloc(even_numbers, even_numbers_length*sizeof(int));

                //printf("array[%d] = %d, result[%d] = %d, even_numbers[%d] = %d\n", i, array[i], i, result[i], even_numbers_length - 2, even_numbers[even_numbers_length - 2]); 
            }
            else
            {
                result[i] = array[i];
                //printf("array[%d] = %d, result[%d] = %d\n", i, array[i], i, result[i]); 
            }
        }

        //arr_print(even_numbers, even_numbers_length - 1);
        //printf("------------------------\n");

        qsort(even_numbers, even_numbers_length-1, sizeof(int), cmp_wa);

        int even_check_count = 0;
        for(int i = 0; i < size; i++)
        {
            if(result[i] == 0)
            {
                //printf("even_check_count = %d\n", even_check_count);
                result[i] = even_numbers[even_check_count];
                //printf("even_numbers[%d] = %d\n", even_check_count, even_numbers[even_check_count]);
                even_check_count++;
            }
            //printf("result[%d] = %d\n", i, result[i]);
        }
        //printf("------------------------\n");

        arr_print(result, size);
        
        /*for(int i = 0; i < size; i++)
        {
            if(answer[i] == result[i])
            {
                continue;
            }
            else
            {
                printf("i = %d, answer = %d, result = %d, NO\n", i, answer[i], result[i]);
                printf("Error\nError\nError\n");
                break;
            }
            printf("OK\n");
        }*/

        free(array);
        free(result);
        free(even_numbers);

        /*printf("Continue? (0 - no): ");
        scanf("%d", &cont);
        if(cont > 0)
            printf("------------------------\n");
    }*/
    return 0;
}