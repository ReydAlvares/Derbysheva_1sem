#include <stdio.h>
int main()
{
    int n = 0, g = 0; 
    float k = 0, n2 = 0;
    scanf("%d%f", &n, &k);
    n2 = k*(float)n;
    g = (int)(n - n2);
    printf("%d", g);
    
    return 0;   
}




