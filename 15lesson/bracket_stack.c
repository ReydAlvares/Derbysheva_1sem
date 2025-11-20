#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 1

typedef char Data;
typedef size_t Stack_Size;

typedef struct 
{
    int n;              //номер первой пустой ячейки массива
    Stack_Size size;           //объём выделенной памяти
    Data * a;
} Stack;

Stack* stack_create(size_t size); // + необходимые действия для создания и инициализации стека размером size ячеек. Теперь эта функция полностью создает и инициализирует стек. Заметьте, что у функции изменились аргументы и тип возвращаемого значения. Гарантируется, что в тестах она будет вызвана, и вызвана единственный раз перед дальнейшей работой со стеком.
void   stack_push(Stack * s, Data x); // кладет число х в стек. +
Data   stack_pop(Stack * s); // достает одно число из стека и возвращает его.
void   stack_print(Stack * s); // + распечатывает через пробел числа, лежащие в стеке. С самого первого до верхнего. В конце переводит строку.
Stack* stack_destroy (Stack * s); // освобождает память. Всю память, занятую стеком, а не часть памяти. Возвращает NULL.
void   print_line(char * line, Stack_Size size);
int    bracket_checker(char* , size_t);

int main()
{
    char*  read = malloc(N * sizeof(char));
    size_t len  = N;
    
    printf("%s\n", !bracket_checker(read, getline(&read, &len, stdin))? "YES": "NO");
    
    free(read);
    return 0;
}

int bracket_checker(char* check, size_t length)
{
    const char* bra_open  = "([<{";
    const char* bra_close = ")]>}";
    Stack*      brackets  = stack_create(length);
    char*       buf_open  = 0;
    char*       buf_close = 0;

    for(size_t i = 0; i < length; i++)
    {
        //printf("i = %lu, el - %c\n", i, check[i]);
        buf_open  = strchr(bra_open, check[i]);
        buf_close = strchr(bra_close, check[i]);

        if(buf_open)
        {
            stack_push(brackets, (Data)(*buf_open));
            //printf("element - %c = %d, size = %d\n", brackets->a[brackets->n - 1], brackets->a[brackets->n - 1], brackets->n);
        }
        if(buf_close)
        {
            if(brackets->a[brackets->n - 1] == bra_open[buf_close - bra_close])
            {
                stack_pop(brackets);
                //printf("Popped - %c, size = %d\n", *buf_close, brackets->n);
            }
            else
            {
                //printf("Error found - %c\n", *buf_close);
                stack_destroy(brackets);
                return 1;
            }
        }
    }
    printf("len = %lu\n", length);

    if(brackets->n)
    {
        stack_destroy(brackets);
        return 1;
    }

    stack_destroy(brackets);
    return 0;
}

Stack * stack_create(size_t size)
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
    if(s->size < (Stack_Size)(s->n + 1))
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

void stack_print(Stack * s)
{
    for(int i = 0; i < s->n; i++)
    {
        printf("%d ", s->a[i]);
    }
    printf("\n");
}

void stack_clear(Stack * s)
{
    free(s->a);
    s->n = 0;
    s->a = NULL;
    s->size = 0;
}

void print_line(char * line, Stack_Size size)
{
    for(Stack_Size i = 0; i < size - 2; i++) // -2 из-за лишнего \n
    {
        printf("%c", line[i]);
    }
    printf("\n");

    return;
}
