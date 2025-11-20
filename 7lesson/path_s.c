#include <stdio.h>

int main()
{
    int L = 0, i = 0, k = 0, s = 0, path = 0;
    scanf("%d%d%d", &L, &k, &s);

    if(L > s)
    {
        printf("%d", i);
    }
    else
    {
        while((path + L) < s)
        {
            path += L; 
            L += k;
            i++;
        }
        if(s%path == 0)
        {
            printf("%d\n", i);
        }
        else
        {
            printf("%d\n", i+1);
        }
    }
    return 0;
}