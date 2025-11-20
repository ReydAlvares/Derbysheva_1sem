#include <stdio.h>
#include <string.h>
#define N 10000

void strget(char* str, int size);
void right(char* right_str);
void your_answer(char* your_answer);

int main()
{
    char right_str[N], my_str[N];

    right(right_str);
    your_answer(my_str);
    printf("%s\n", strcmp(right_str, my_str) == 0? "YES": "NO");

    return 0;
}

void right(char* right_str)
{
    printf("right answer:\n");
    strget(right_str, N);
}

void your_answer(char* your_answer)
{
    printf("your answer:\n");
    //fgets(your_answer, N, stdin);
    strget(your_answer, N);
}