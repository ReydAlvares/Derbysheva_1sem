#include <stdio.h>
#include <stdlib.h>
#define cards_count 5
#define max_steps 1000000

typedef int Data;

//typedef struct Node Node;

struct Node
{
    Data data;
    struct Node* prev;
    struct Node* next;
};

void list_init(struct Node * list); // инициализация

void list_insert(struct Node * list, struct Node * t); //после list вставить t
void list_insert_before(struct Node * list, struct Node * t); // перед list вставить t
void list_remove(struct Node * t);

struct Node * list_push_front(struct Node * list, Data d); // добавить в начало списка
struct Node * list_push_back(struct Node * list, Data d); // добавить в конец списка

Data list_pop_front(struct Node * list); // удалить из начала списка
Data list_pop_back(struct Node * list); // удалить из конца списка
Data list_delete(struct Node * t); // удалить узел t

void list_print (struct Node * list); // распечатать список (не включая замок)
int list_is_empty(struct Node * list); // пустой?

void list_clear(struct Node * list); // удалить все, кроме замочка

struct Node * list_create();
void list_destroy(struct Node * list);

void game(struct Node* player_1, struct Node* player_2);
void step(struct Node* list1, struct Node* list2);

int main()
{
    struct Node* player_1 = list_create();
    struct Node* player_2 = list_create();

    game(player_1, player_2);

    list_destroy(player_1);
    list_destroy(player_2);

    return 0;
}

void list_init(struct Node * list)
{
    list->next = list->prev = list;
}

struct Node* list_create()
{
    struct Node * list = malloc(sizeof(struct Node));
    list_init(list);

    return list;
}

void list_insert(struct Node * list, struct Node * t)
{
    struct Node * q = list->next;

    t->prev = list;
    t->next = q;
    list->next = t;
    q->prev = t;
}

void list_insert_before(struct Node * list, struct Node * t)
{
    list_insert(list->prev, t);
}

void list_remove(struct Node * t)
{
    struct Node * p = t->prev;
    struct Node * q = t->next;
    p->next = q;
    q->prev = p;
}

struct Node * list_push_front(struct Node * list, Data d)
{
    struct Node * t = malloc(sizeof(struct Node));
    list_insert(list, t);
    t->data = d;

    return t;
}

struct Node * list_push_back(struct Node * list, Data d)
{
    return list_push_front(list->prev, d);
}

Data list_delete(struct Node * t)
{
    Data x = t->data;
    list_remove(t);
    free(t);

    return x;
}

Data list_pop_front(struct Node * list)
{
    return list_delete(list->next);
}

Data list_pop_back(struct Node * list)
{
    return list_delete(list->prev);
}


void list_print (struct Node * list)
{
    struct Node* buf = list->next;
        
    while(buf != list)
    {
        printf("%d ", buf->data);
        buf = buf->next;
    }

    printf("\n");
}

int list_is_empty(struct Node * list)
{
    return list->next == list;
}

void list_clear(struct Node * list)
{
    while(!list_is_empty(list))
    {
        list_pop_front(list);
    }
}

void list_destroy(struct Node * list)
{
    list_clear(list);
    free(list);
}
void distribution(struct Node* list)
{
    Data card = 0;

    for(int i = 0; i < cards_count; i++)
    {
        scanf("%d", &card);
        list_push_back(list, card);
    }
}

void step(struct Node* list1, struct Node* list2)
{
    Data res = list1->next->data - list2->next->data;

    if((res > 0 && res < 9) || res == -9)
    {
        list_push_back(list1, list_pop_front(list1));
        list_push_back(list1, list_pop_front(list2)); // first won
    }
    
    if((res < 0 && res > -9) || res == 9)
    {
        list_push_back(list2, list_pop_front(list1));
        list_push_back(list2, list_pop_front(list2));  // second won
    }
}

void game(struct Node* player_1, struct Node* player_2)
{

    distribution(player_1);
    distribution(player_2);

    for(int i = 0; i < max_steps; i++)
    {
        printf("New step: %d\n", i);
        list_print(player_1);
        list_print(player_2);

        if(list_is_empty(player_1))
        {
            printf("%s %d\n", "second", i);
            return;
        }

        if(list_is_empty(player_2))
        {
            printf("%s %d\n", "first", i);
            return;
        }

        step(player_1, player_2);

        printf("After: \n");
        list_print(player_1);
        list_print(player_2);
        printf("------------\n");
    }

    printf("botva\n");
}