#include <stdio.h>

typedef int Data;

#define N 8
typedef struct {
    Data a[N];      // место для данных
    unsigned int n; // сколько данных хранится
} Stack;

void print(Stack * s) {
    for(unsigned int i = 0; i < s->n; i++)
        printf("%d ", s->a[i]);
    printf("\n");
} 

void init(Stack * st) {
    st->n = 0;
} 

int main()
{
    Stack stack;            // создаем стек
    Stack * st = &stack;    // указатель на созданный стек

    init(st);
    print(st);              // ничего не печатается

    return 0;
}
