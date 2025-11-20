#include <stdio.h>
#include <stdlib.h>

void arr_input(int * arr, int size)
{
    for(int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
}

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

    if(a%10 == a && b%10 == b)
    {
        return (a%10 > b%10) - (a%10 < b%10);
    }

    printf("a = %d, b = %d\n", a, b);
    if(a%10 == b%10)
    {
        a /= 10;
        b /= 10;
        return cmp_wa(&a, &b);
    }
    else
    {
        return (a%10 > b%10) - (a%10 < b%10);
    }
    
}

int main()
{
    int size = 0;
    scanf("%d", &size);
    
    int * array = malloc(size*sizeof(int));
    arr_input(array, size);
    
    qsort(array, size, sizeof(int), cmp_wa);

    arr_print(array, size);

    free(array);

    return 0;
}