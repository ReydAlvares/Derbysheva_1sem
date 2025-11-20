#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 1000

int cmp_str_in(const void * p1, const void * p2)
{
    return (*(char*)p1 > *(char*)p2) - (*(char*)p1 < *(char*)p2);
}

int main()
{
    char str[N] = {};
    fgets(str, N, stdin);

    int point = strstr(str, ".") - str;
    str[point+1] = '\0';

    qsort(str, point, sizeof(char), cmp_str_in);
    printf("%s\n", str);
    return 0;

}