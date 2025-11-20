#include <stdio.h>
#include <stdlib.h>

typedef struct Point {
    int x;
    int y;
}Point;

void arr_input(Point * arr, int size)
{
    for(int i = 0; i < size; i++)
    {
        scanf("%d%d", &arr[i].x, &arr[i].y);
    }
}

void arr_print(Point * arr, int size)
{
    //printf("--------------\n");
    for(int i = 0; i < size; i++)
    {
        printf("%d %d\n", arr[i].x, arr[i].y);
    }
    printf("\n");
}

int cmp_point(const void * p1, const void * p2)
{
    Point p_1 = *(Point*)p1;
    Point p_2 = *(Point*)p2;

    unsigned long int dist1 = p_1.x * p_1.x + p_1.y * p_1.y;
    unsigned long int dist2 = p_2.x * p_2.x + p_2.y * p_2.y;
    //printf("dist 1 = %lu, dist 2 = %lu\n, between = %d or %lu\n", dist1, dist2, (dist1 > dist2) - (dist1 < dist2), dist1 - dist2);
    if(dist1 == dist2)
    {
        if(p_1.x == p_2.x)
        {
            return (p_1.y > p_2.y) - (p_1.y < p_2.y);
        }
        else
            return (p_1.x > p_2.x) - (p_1.x < p_2.x);
    }
    else 
        return (dist1 > dist2) - (dist1 < dist2);
}

int main()
{
    int count = 0;
    scanf("%d", &count);

    Point * array = malloc(count * sizeof(Point));
    arr_input(array, count);

    qsort(array, count, sizeof(Point), cmp_point);
    arr_print(array, count);

    free(array);
    return 0;
}