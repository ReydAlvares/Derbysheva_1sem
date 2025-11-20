#include <stdio.h>
#define LENGTH 9

int main()
{
    int count[LENGTH] = {0}; //количество купюр и монет
    int money[LENGTH] = {5000, 1000, 500, 100, 50, 10, 5, 2, 1};
    int rubbles = 0;
    scanf("%d", &rubbles);

    for(int i = 0; i < LENGTH; i++)
    {
        count[i] = rubbles/money[i];
        rubbles -= count[i] * money[i];
    }
    for(int i = 0; i < LENGTH; i++)
        {
            printf("%d %d\n", money[i], count[i]);
        }

    return 0;
}