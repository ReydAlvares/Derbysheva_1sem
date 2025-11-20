#include <stdio.h>

int delim(int a[], int i, int j);
    // Функция делит конфеты детей a[i] и a[j].
    // Отдает школьнику (return) лишние конфеты.

int all_equal(int a[], int n);
    // Проверяет, все ли числа в массиве a одинаковые.
    // Возвращает 1 (все одинаковые) или 0 (не все)
    // вы писали раньше такую задачу

int make_all_happy(int a[], int n);
    // Дети делят конфеты, "лишние" конфеты возвращают

int main()
{
    int a[100];     // ребенок i имеет a[i] конфет
    int n;          // всего детей

    scanf("%d", &n);                        // читаем входные данные
    for(int i = 0; i < n; i++)
        scanf("%d", a+i);

    int schoolboy = make_all_happy(a, n);   // делим
    printf("%d %d\n", schoolboy, a[0]);     // печатаем ответ

    return 0;
}

int delim(int a[], int i, int j)
{
    if((a[i]+a[j])%2 == 1)
    {
        a[i] = (a[i] + a[j] - 1)/2;
        a[j] = a[i];
        return 1;
    }
    else
    {
        a[i] = (a[i] + a[j])/2;
        a[j] = a[i];
        return 0;
    }
}

int all_equal(int a[], int n)
{
    for(int i = 0; i < n-1; i++)
    {
        if(a[i] != a[i+1])
        {
            return 0;
        }
    }
    return 1;
}

int make_all_happy(int a[], int n)
{
    int sum = 0;
    while(all_equal(a, n) == 0)
    {
        for(int i = 0; i <= n-1; i++)
        {
            if(i == n-1)
            {
                sum += delim(a, n-1, 0);
            }
            else
            {
                sum += delim(a, i, i+1);
            }
        }
    }
    return sum;
}