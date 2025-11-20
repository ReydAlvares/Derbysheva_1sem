#include <stdio.h>
#include <stdlib.h>

typedef int Data;

typedef struct {
    int n;              //номер первой пустой ячейки массива
    int size;           //объём выделенной памяти
    Data * a;
} Stack;

Stack * stack_create (int size); // + необходимые действия для создания и инициализации стека размером size ячеек. Теперь эта функция полностью создает и инициализирует стек. Заметьте, что у функции изменились аргументы и тип возвращаемого значения. Гарантируется, что в тестах она будет вызвана, и вызвана единственный раз перед дальнейшей работой со стеком.
void stack_push (Stack * s, Data x); // кладет число х в стек. +
Data stack_pop (Stack * s); // достает одно число из стека и возвращает его.
Data stack_get (Stack * s); // возвращает число, лежащее на верхушке стека, не изменяя состояния стека.
int stack_is_empty (Stack * s); // возвращает 1, если стек пуст; 0 в противном случае.
void stack_print (Stack * s); // + распечатывает через пробел числа, лежащие в стеке. С самого первого до верхнего. В конце переводит строку.
int stack_size (Stack * s); // возвращает количество элементов, лежащих в стеке.
void stack_clear (Stack * s); // очищает стек, не разрушая его.
Stack * stack_destroy (Stack * s); // освобождает память. Всю память, занятую стеком, а не часть памяти. Возвращает NULL.

int main()
{
    Stack * sp = stack_create(3);
    int x = 0;

    printf("is_empty=%d\n", stack_is_empty(sp));    // is_empty=1
    printf("size=%d\n", stack_size(sp));            // size=0

    stack_push(sp, 5);
    stack_push(sp, 19);
    stack_push(sp, -2);
    stack_print(sp);                                // 5 19 -2

    stack_push(sp, 27);
    stack_print(sp);                                // 5 19 -2 27

    printf("is_empty=%d\n", stack_is_empty(sp));    // is_empty=0
    printf("size=%d\n", stack_size(sp));            // size=4

    x = stack_pop(sp);
    printf("x=%d\n", x);                            // x=27

    x = stack_pop(sp);
    printf("x=%d\n", x);                            // x=-2

    stack_print(sp);                                // 5 19

    while (!stack_is_empty(sp)) {
        x = stack_pop(sp);
        printf("x=%d\n", x);
        stack_print(sp);
    }
                                                    // x=19
                                                    // 5
                                                    // x=5
                                                    // пустая строка

    if (NULL == stack_destroy(sp))
        printf("end\n");                           // end
    return 0;
}

Stack * stack_create(int size)
{
    Stack* st = malloc(sizeof(Stack));
    st->n = 0;
    st->a = malloc(size * sizeof(Data));
    st->size = size;

    //printf("Stack created, got %lu\n", size*sizeof(Data));
    return st;
}

Stack * stack_destroy(Stack * s)
{
    if(s != 0)
    {
        free(s->a);
        free(s);
    }
    //printf("Stack destroyed\n");
    
    return NULL;
}

void stack_push(Stack * s, Data x)
{
    if(s->size < s->n + 1)
    {
        s->size += 10;
        s->a = realloc(s->a, s->size * sizeof(Data));
    }

    s->a[s->n] = x;
    s->n++;
}

Data stack_pop(Stack * s)
{
    if(s->n > 0)
    {
        if(s->size - s->n > 10)
        {
            s->size -= 10;
            s->a = realloc(s->a, s->size * sizeof(Data));
        }
        s->n--;
    }
    if(s->n < 0) 
        s->n = 0;
    
    return s->a[s->n];
}

Data stack_get(Stack * s)
{
    return s->a[(s->n) - 1];
}

int stack_is_empty (Stack * s)
{
    return s->n == 0;
}

void stack_print(Stack * s)
{
    for(int i = 0; i < s->n; i++)
    {
        printf("%d ", s->a[i]);
    }
    printf("\n");
}

int stack_size(Stack * s)
{
    return s->n;
}

void stack_clear(Stack * s)
{
    free(s->a);
    s->n = 0;
    s->a = NULL;
    s->size = 0;
}




