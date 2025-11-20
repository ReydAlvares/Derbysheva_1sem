#include <stdio.h>
#define N 8

typedef int Data;
typedef struct {
    Data a[N];      // место для данных
    unsigned int n; // сколько данных хранится
} Stack;
//int stack_size (Stack * s); //если использовать функцию в других функциях при таком коде, где ты пишешь функции 
//выше main, то необходимо либо обозначить функцию, либо ставить выше тех, где используем

int stack_size (Stack * s) // возвращает количество элементов, лежащих в стеке
{
    return s->n;
}

void stack_init (Stack * s) // необходимые действия для создания и инициализации стека. (Когда мы создаем локальную переменную, то она не инициализируется 0, т.е. в поле n может лежать любое число.)
{
    s->n = 0;
}

void stack_push (Stack * s, Data x) // кладет число х в стек
{
    s->a[s->n++] = x;
}

Data stack_pop (Stack * s) //достает одно число из стека и возвращает его
{
    printf("n before - %d ", s->n);
    return s->a[s->n--];
}

Data stack_get (Stack * s) // возвращает число, лежащее на верхушке стека, не изменяя состояния стека
{
    return s->a[s->n];
}

void stack_clear (Stack * s) // очищает стек (функция stack_is_empty должна вернуть 1).
{
    //можно создать новый массив с случайными значениями длиной = заполненности нашего массива, 
    //а потом просто скопировать из одного в другой. Можно просто обнулить значения у нашего)
    s->n = 0;
}

void stack_print (Stack * s) // распечатывает через пробел числа, лежащие в стеке. С самого первого до верхнего. В конце переводит строку.
{
    for(unsigned int i = 0; i < s->n; i++)
    {
        printf("%d ", s->a[i]);
    }
    printf(" length - %u\n", stack_size(s));

    return;
}

int stack_is_empty (Stack * s) // возвращает 1 если стек пуст, иначе возвращает 0.
{
    if(stack_size(s))
        return 1;

    return 0;
}

int stack_is_full (Stack * s) // возвращает 1 если стек полон (в него нельзя добавлять данные, это приведет к переполнению), иначе возвращает 0
{
    return stack_size(s) == sizeof(s->a)/sizeof(s->a[0]);
}

int main()
{
    Stack main_st;
    Stack* where_st = &main_st;

    stack_init(where_st);
    stack_print(where_st);

    while(!stack_is_full(where_st))
    {
        stack_push(where_st, 5);
        stack_print(where_st);
    }

    stack_clear(where_st);
    stack_print(where_st);
    
    return 0;
}