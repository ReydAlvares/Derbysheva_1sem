#include <stdio.h>
#include <math.h>

float dist(int x1, int y1, int x2, int y2);
float area(int x1, int y1, int x2, int y2, int x3, int y3);
int main()
{
    float s = 0;
    int x1 = 0, y1 = 0;
    int x2 = 0, y2 = 0;
    int x3 = 0, y3 = 0;
    
    scanf("%d%d", &x1, &y1);
    scanf("%d%d", &x2, &y2);
    scanf("%d%d", &x3, &y3);

    s = area(x1, y1, x2, y2, x3, y3);
    printf("%0.3f", s);

    return 0;
}

float dist(int x1, int y1, int x2, int y2)
{
    int r1 = 0, r2 = 0;
    r1 = x2 - x1;
    r2 = y2 - y1;
    return sqrt(r1*r1 + r2*r2);
}

float area(int x1, int y1, int x2, int y2, int x3, int y3)
{
    float a = 0, b = 0, c = 0, p = 0;
    a = dist(x1, y1, x2, y2);
    b = dist(x1, y1, x3, y3);
    c = dist(x3, y3, x2, y2);
    p = (a+b+c)/2.0;

    return sqrt(p*(p-a)*(p-b)*(p-c));
}