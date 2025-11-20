#include <stdio.h>
void rotateC(int *x1, int *y1, int *x2, int *y2);

int main()
{
    int xlt = 0, ylt = 0, xrb = 0, yrb = 0;
    scanf("%d%d%d%d", &xlt, &ylt, &xrb, &yrb);
    rotateC(&xlt, &ylt, &xrb, &yrb);
    printf("%d %d %d %d\n", xlt, ylt, xrb, yrb);
    return 0;
}

void rotateC(int *x1, int *y1, int *x2, int *y2)
{
    int t = 0;
    printf("%d %d %d %d\n", *x1, *y1, *x2, *y2);
    t = (*x2 - *x1 -*y1 + *y2)/2;
    printf("t = %d\n", t);
    *x1 += t;
    *x2 -= t;
    *y1 += t;
    *y2 -= t;
    printf("%d %d %d %d\n", *x1, *y1, *x2, *y2);
}