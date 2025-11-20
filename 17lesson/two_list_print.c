#include <stdio.h>

typedef int Data;

typedef struct Node Node;

struct Node
{
    Data data;
    Node* prev;
    Node* next;
};

void list_print (Node * list);

int main()
{
    Node z;
    Node a, b, c;
    Node* list = &z;

    z.data = 0;  z.next = &a;  z.prev = &c;
    a.data = 3;  a.next = &b;  a.prev = &z;
    b.data = 17;  b.next = &c;  b.prev = &a;
    c.data = 21;  c.next = &z;  c.prev = &b;

    list_print(list);

    return 0;
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