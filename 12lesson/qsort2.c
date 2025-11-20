#include <stdio.h>
#include <stdlib.h>

void arr_input(float * arr, int size);
void arr_print(float * arr, int size);
int cmp_in(const void * p1, const void * p2);
int main()
{
    int size = 0;
    scanf("%d", &size);
    
    float * array = malloc(size*sizeof(int));
    arr_input(array, size);
    
    qsort(array, size, sizeof(float), cmp_in);
    arr_print(array, size);
    
    free(array);
    return 0;
}

int cmp_in(const void * p1, const void * p2)
{
    return (*(float*)p1 > *(float*)p2) - (*(float*)p1 < *(float*)p2);
}

void arr_input(float * arr, int size)
{
    for(int i = 0; i < size; i++)
    {
        scanf("%f", &arr[i]);
    }
}

void arr_print(float * arr, int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
}


