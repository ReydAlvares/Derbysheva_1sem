#include <stdio.h>
#define N 1000
int main(){
    int a[N];           // массив для N чисел
    int i;              // номер текущей ячейки
    int n;              // сколько чисел дано

    scanf("%d", &n);
    // читаем n чисел в массив a
    for(i=0; i<n; i++)
        scanf("%d", &a[i]);
    int r = n-1; //last array's element

    int b[n];

    // печатаем числа
    for(i=0; i < n ; i++) 
    {
        b[r-i] = a[i];
    }

    for(i=0; i < n ; i++) 
    {
        printf("%d ", b[i]);
    }
    
    printf("\n");
    return 0;
}