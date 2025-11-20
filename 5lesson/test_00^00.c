#include <stdio.h>

typedef struct{
    int h; // часы
    int min; // минуты (от 0 до 59)
}TicTac;

int main()
{
    printf("%02d:%02d", 20, 33);
    return 0;
}