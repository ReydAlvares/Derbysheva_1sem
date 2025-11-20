#include <stdio.h>
#include <stdlib.h>


typedef int Data;
struct Node {
    Data val;               // данные, которые хранятся в одном элементе
    struct Node * next;     // указатель на следующий элемент списка
}Node;
typedef struct Node * List;

List list_create(); //необходимые действия для создания и инициализации списка (просто вернуть NULL).
void list_push(List * plist, Data x); // кладет число х первым элементом списка.
Data list_pop(List * plist); // достает первое число из списка и возвращает его.
Data list_get(List list); // возвращает число, лежащее в первом узле, не изменяя состояния списка.
void list_print(List list); // распечатывает через пробел числа, лежащие в списке. С самого первого до последнего. В конце переводит строку. Полезна для отладки прочих функций.
int list_size(List list); // возвращает количество элементов, лежащих в списке.
int list_is_empty(List list); // возвращает 1, если список пустой; иначе возвращает 0.
void list_clear(List * plist); // опустошает список, освобождая память. После этого можно опять добавлять элементы в список.

int main()
{
    List list = list_create();
    list_print(list);                               // пустая строка
    printf("is_empty = %d\n", list_is_empty(list)); // is_empty = 1
    printf("size = %d\n", list_size(list));         // size = 0

    list_push(&list, 21);
    list_print(list);                               // 21
    list_push(&list, 17);
    list_print(list);                               // 17 21
    list_push(&list, 3);
    list_print(list);                               // 3 17 21
    printf("is_empty = %d\n", list_is_empty(list)); // is_empty = 0
    printf("size = %d\n", list_size(list));         // size = 3

    Data x = list_pop(&list);
    printf("pop %d\n", x);                          // pop 3
    list_print(list);                               // 17 21
    printf("size = %d\n", list_size(list));        // size = 2

    list_clear(&list);
    list_print(list);                               // пустая строка
    printf("is_empty = %d\n", list_is_empty(list)); // is_empty = 1
    printf("size = %d\n", list_size(list));         // size = 0

    return 0;
}

List list_create()
{
    List list = NULL;
    //printf("List created\n");

    return list;
}

void list_print(List list)
{
    List for_print = list;

    while(for_print)
    {
        printf("%d ", for_print->val);
        for_print = for_print->next;
    }
    printf("\n");

    //printf("-----List printed\n");
}

int list_size(List list)
{
    int size = 0;

    List for_size = list;

    while(for_size)
    {
        if(!for_size->next)
        {
            size++;
            return size;
        }

        for_size = for_size->next;
        size++;
    }

    return size;
}

void list_push(List * plist, Data x)
{
    if (!(*plist))
    {
        *plist = malloc(sizeof(struct Node));
        (*plist)->next = NULL;
        (*plist)->val = x;

        return;
    }

    List new_node = malloc(sizeof(struct Node));

    new_node->val = x;
    new_node->next = *plist;

    *plist = new_node;

}

Data list_pop(List * plist)
{
    List buf = *plist;
    Data x = buf->val;
    //printf("p = %p, plist = %p, x = %d, next = %p\n", buf, plist, x, (*plist)->next);
    *plist = (*plist)->next;
    //printf("*plist = %p\n", plist);

    free(buf);
    //printf("Freed\n");

    //printf("Popped %d\n", x);
    return x;
}

void list_clear(List * plist)
{
    while(!list_is_empty(*plist))
    {
        list_pop(plist);
    }

    *plist = NULL;

    //printf("List cleared\n");
}

Data list_get(List list)
{
    return list->val;
}

int list_is_empty(List list)
{
    return list == 0;
}