#include <stdio.h>
#include <stdlib.h>

typedef int Data;

typedef struct Node Node;

struct Node
{
    Data data;
    Node* prev;
    Node* next;
};

void list_init(Node * list); // инициализация

void list_insert(Node * list, Node * t); //после list вставить t
void list_insert_before(Node * list, Node * t); // перед list вставить t
void list_remove(Node * t);

Node * list_push_front(Node * list, Data d); // добавить в начало списка
Node * list_push_back(Node * list, Data d); // добавить в конец списка

Data list_pop_front(Node * list); // удалить из начала списка
Data list_pop_back(Node * list); // удалить из конца списка
Data list_delete(Node * t); // удалить узел t

void list_print (Node * list); // распечатать список (не включая замок)
int list_is_empty(Node * list); // пустой?

void list_clear(Node * list); // удалить все, кроме замочка

Node * list_create();
void list_destroy(Node * list);

void test();
void test_allocs();

int main()
{
    test();
    test_allocs();

    return 0;
}

void list_init(Node * list)
{
    list->next = list->prev = list;
}

Node* list_create()
{
    Node * list = malloc(sizeof(Node));
    list_init(list);

    return list;
}

void list_insert(Node * list, Node * t)
{
    Node * q = list->next;

    t->prev = list;
    t->next = q;
    list->next = t;
    q->prev = t;
}

void list_insert_before(Node * list, Node * t)
{
    list_insert(list->prev, t);
}

void list_remove(Node * t)
{
    Node * p = t->prev;
    Node * q = t->next;
    p->next = q;
    q->prev = p;
}

Node * list_push_front(Node * list, Data d)
{
    Node * t = malloc(sizeof(Node));
    list_insert(list, t);
    t->data = d;

    return t;
}

Node * list_push_back(Node * list, Data d)
{
    return list_push_front(list->prev, d);
}

Data list_delete(Node * t)
{
    Data x = t->data;
    list_remove(t);
    free(t);

    return x;
}

Data list_pop_front(Node * list)
{
    return list_delete(list->next);
}

Data list_pop_back(Node * list)
{
    return list_delete(list->prev);
}


void list_print (Node * list)
{
    Node* buf = list->next;
        
    while(buf != list)
    {
        printf("%d ", buf->data);
        buf = buf->next;
    }

    printf("\n");
}

int list_is_empty(Node * list)
{
    return list->next == list;
}

void list_clear(Node * list)
{
    while(!list_is_empty(list))
    {
        list_pop_front(list);
    }
}

void list_destroy(Node * list)
{
    list_clear(list);
    free(list);
}

void test_allocs()
{
    /*Node * list = malloc(sizeof(Node));
    list_init(list);
    list_print(list);                    // пустой список


    Node * t;
    t = list_push_front(list, 21);
    printf("push %d: ", t->data);
    list_print(list);                    // 21*/

    Data test_data1[] = {21, 17, 3};    // для вставки сначала
    Data test_data2[] = {10, 8};        // для вставки с конца


    Node * list = malloc(sizeof(Node));
    list_init(list);
    list_print(list);                    // пустой список


    Node * t;
    for(size_t i = 0; i < sizeof(test_data1)/sizeof(test_data1[0]); i++) {
        t = list_push_front(list, test_data1[i]);
        printf("push_front %d: ", t->data);
        list_print(list);
    }
    // 3 17 21


    for(size_t i = 0; i < sizeof(test_data2)/sizeof(test_data2[0]); i++) {
        t = list_push_back(list, test_data2[i]);
        printf("push_back %d: ", t->data);
        list_print(list);
    }

    Node * t5 = list->next->next;    // узел с числом 17
    Data res = list_delete(t5);
    printf("deleted %d: ", res);    // deleted 17:
    list_print(list);               // 3 21 10 8

    res = list_pop_front(list);
    printf("pop front %d: ", res);  // 3:
    list_print(list);               // 21 10 8


    res = list_pop_back(list);
    printf("pop back %d: ", res);  // 8:
    list_print(list);              // 21 10


    list_clear(list);

    free(list);
}

void test()
{
    Node z;
    Node* list = &z;

    Node a, b, c;
    Node in1 = {.data = 10}, in2 = {.data = 12};
    
    a.data = 3;
    b.data = 49;
    c.data = 7;

    list_init(list);
    printf("List is empty? - %s\n", list_is_empty(list)? "Yes": "No");
    //printf("list - %p, list->next %p, list->prev = %p\n", list, list->next, list->prev);
    list_print(list);

    list_insert(list, &c);
    list_print(list);

    list_insert(list, &b);
    list_print(list);

    list_insert(list, &a);
    list_print(list);

    list_insert(&a, &in1);
    list_print(list);

    list_insert(&c, &in2);
    list_print(list);

    list_remove(&a);
    list_print(list);

    printf("List is empty? - %s\n", list_is_empty(list)? "Yes": "No");
}