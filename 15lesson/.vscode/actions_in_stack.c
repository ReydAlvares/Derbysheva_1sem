#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define N 17

typedef int Data;
typedef size_t Stack_Size;

typedef struct 
{
    int n;              //номер первой пустой ячейки массива
    Stack_Size size;           //объём выделенной памяти
    Data * a;
} Stack;

Stack* stack_create(size_t size); 
void   stack_push(Stack * s, Data x);
Data   stack_pop(Stack * s);
Stack* stack_destroy(Stack * s);
int calculator(char* , size_t);

int main()
{
    char*  read = malloc(N * sizeof(char));
    size_t len  = N;

    printf("%d\n", calculator(read, getline(&read, &len, stdin)));
    free(read);

    return 0;
}

int calculator(char* line, size_t len)
{
    int sum = 0;
    const char* action_signes = "+-*";
    Stack * expression = stack_create(N);

    for(size_t i = 0; i < len; i++)
    {
        char* buf_sign = strchr(action_signes, line[i]);

        if(buf_sign)
        {   
            int a = stack_pop(expression);
            int b = stack_pop(expression);
            //printf("a = %d, b = %d\n", a, b);

            switch((int)*buf_sign)
            {
                case '+': 
                    sum = a + b;
                    break;
                case '-':
                    sum = b - a;
                    break;
                case '*':
                    sum = a * b;
                    break; 
            }

            //printf("sum = %d\n", sum);
            stack_push(expression, sum);
        }
        else
        {
            //printf("line[i] = %c\n", (Data)line[i]);
            if(isdigit(line[i]))
            {
                //printf("Stacked\n");
                stack_push(expression, (int)(line[i]) - 48);
            }
        }
    }

    sum = stack_pop(expression);
    stack_destroy(expression);

    return sum;
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