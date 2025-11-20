#include <stdio.h>\

int nod(int a, int b);
int main()
{
    int a = 0, b = 0;

    scanf("%d%d", &a, &b);
    int res = nod(a, b);
    printf("%d", res);

    return 0;
}

int nod(int a, int b)
{
    if( a%b == 0)
        return b;
    int res = nod(b, a%b);
    return res;
}