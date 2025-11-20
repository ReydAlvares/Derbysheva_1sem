#include <stdio.h>

int main()
{
    float s = 0, w = 0, ch = 0;
    int res = 0;
    scanf("%f%f%f", &s, &w, &ch);

    res = (int)((s/w)/ch);
    printf("%d", res);

    return 0;
}