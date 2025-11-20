#include <stdio.h>

typedef struct Point {
    int x;
    int y;
}Point;

int cmp_Point(const void * p1, const void * p2)
{
    Point p_1 = *(Point*)p1;
    Point p_2 = *(Point*)p2;

    unsigned long int dist1 = p_1.x * p_1.x + p_1.y * p_1.y;
    unsigned long int dist2 = p_2.x * p_2.x + p_2.y * p_2.y;
    //printf("dist 1 = %lu, dist 2 = %lu\n, between = %d or %lu\n", dist1, dist2, (dist1 > dist2) - (dist1 < dist2), dist1 - dist2);

    return (dist1 > dist2) - (dist1 < dist2);
}

int main()
{
    Point a, b;
    scanf("%d%d", &a.x, &a.y);
    scanf("%d%d", &b.x, &b.y);

    int res = cmp_Point(&a, &b);

    if (res < 0)
        printf("<\n");
    else if (res > 0)
        printf(">\n");
    else
        printf("=\n");

    return 0;
}