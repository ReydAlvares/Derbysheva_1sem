#include <stdio.h>
#include <stdlib.h>
#define N 10

typedef int Data;
typedef struct Node Node;
typedef struct List List;

struct Node
{
    Data val;
    Node* left;
    Node* right;
};

/*struct List
{
    Data data;
    List* prev;
    List* next;
};

void list_init(List * list); // инициализация

void list_insert(List * list, List * t); //после list вставить t
void list_insert_before(List * list, List * t); // перед list вставить t
void list_remove(List * t);

List * list_push_front(List * list, Data d); // добавить в начало списка
List * list_push_back(List * list, Data d); // добавить в конец списка

Data list_pop_front(List * list); // удалить из начала списка
Data list_pop_back(List * list); // удалить из конца списка
Data list_delete(List * t); // удалить узел t

void list_print (List * list); // распечатать список (не включая замок)
int list_is_empty(List * list); // пустой?

void list_clear(List * list); // удалить все, кроме замочка

List * list_create();
void list_destroy(List * list);*/

void tree_print(Node * tree);
Node * tree_destroy(Node * tree);
Node * tree_add(Node * tree, Data val);
Data tree_max_height(struct Node * tree);

int main()
{
    Node * tree = NULL;
    int data = 1;

    while(1)
    {
        scanf("%d", &data);
        if(!data)
        {
            break;
        }

        tree = tree_add(tree, data);
    }

    tree_print(tree);
    printf("\n");

    /*List * queue = malloc(sizeof(List));
    list_init(queue);

    list_push_front(queue, tree->val);
    Node * buf_left = tree;
    Node * buf_right = tree;

    while(!list_is_empty(queue))
    {
        printf("%d ", list_pop_front(queue));
        
        if(buf_left->left)
        {
            list_push_front(queue, buf_left->left->val);

            buf_left = buf_left->left;
        }

        if(buf_right->right)
        {
            list_push_front(queue, buf_right->right->val);
            list_push_front(queue, buf_right->left->val);

            buf_right = buf_right->right;
        }
    }   
    printf("\n");*/

    tree = tree_destroy(tree);
    //list_destroy(queue);
    return 0;
}


Node * tree_add(Node * tree, Data x)
{
    if(tree == NULL)
    {
        Node* p = malloc(sizeof(Node));
        p->val = x;
        p->left = p->right = NULL;

        return p;
    }

    if(tree->val > x)
    {
        tree->left = tree_add(tree->left, x);
    }

    if(tree->val < x)
    {
        tree->right = tree_add(tree->right, x);
    }

    return tree;
}

Node * tree_destroy(Node * tree)
{
    if(tree == NULL)
    {
        return NULL;
    }

    tree_destroy(tree->left);
    tree_destroy(tree->right);
    free(tree);

    return NULL;
}

void tree_print(Node * tree)
{
    if(tree == NULL)
    {
        return;
    }

    tree_print(tree->left);
    printf("%d ", tree->val);
    tree_print(tree->right);
}


/*void list_init(List * list)
{
    list->next = list->prev = list;
}

List* list_create()
{
    List * list = malloc(sizeof(List));
    list_init(list);

    return list;
}

void list_insert(List * list, List * t)
{
    List * q = list->next;

    t->prev = list;
    t->next = q;
    list->next = t;
    q->prev = t;
}

void list_insert_before(List * list, List * t)
{
    list_insert(list->prev, t);
}

void list_remove(List * t)
{
    List * p = t->prev;
    List * q = t->next;
    p->next = q;
    q->prev = p;
}

List * list_push_front(List * list, Data d)
{
    List * t = malloc(sizeof(List));
    list_insert(list, t);
    t->data = d;

    return t;
}

List * list_push_back(List * list, Data d)
{
    return list_push_front(list->prev, d);
}

Data list_delete(List * t)
{
    Data x = t->data;
    list_remove(t);
    free(t);

    return x;
}

Data list_pop_front(List * list)
{
    return list_delete(list->next);
}

Data list_pop_back(List * list)
{
    return list_delete(list->prev);
}


void list_print (List * list)
{
    List* buf = list->next;
        
    while(buf != list)
    {
        printf("%d ", buf->data);
        buf = buf->next;
    }

    printf("\n");
}

int list_is_empty(List * list)
{
    return list->next == list;
}

void list_clear(List * list)
{
    while(!list_is_empty(list))
    {
        list_pop_front(list);
    }
}

void list_destroy(List * list)
{
    list_clear(list);
    free(list);
}*/

Data tree_max_height(struct Node * tree)
{
    if(tree == NULL)
    {
        return 0;
    }

    int left  = tree_max_height(tree->left);
    int right = tree_max_height(tree->right);

    return max(left, right) + 1;
}
