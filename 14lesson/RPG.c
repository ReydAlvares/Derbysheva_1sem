#include <stdio.h>
#include <stdlib.h>
#define N 1000
typedef struct
{
    unsigned int ai;
    unsigned int pi;
    unsigned int price;
}Item;

void input(Item * items, int count)
{
    int i;
    for(i = 0; i < count; i++)
    {
        scanf("%u%u%u", &(items + i)->ai, &(items + i)->pi, &(items + i)->price);
        //printf("i - %d, price = %u\n", i, (items + i)->price);
    }

}

void print(Item * items, int count)
{
    int i;
    for(i = 0; i < count; i++)
        printf("%u %u %u\n", (items + i)->ai, (items + i)->pi, (items + i)->price);
}

int cmp(const void * p1, const void * p2)
{
    Item x = *(Item*)p1;
    Item y = *(Item*)p2;

    //printf("Start, x = %u %u %u\n y = %u %u %u\n", x.pi, x.ai, x.price, y.pi, y.ai, y.price);

    if(x.pi == y.pi)
    {
        //printf("pi == pi for %u and %u\n", x.pi, y.pi);

        if(x.ai == y.ai)
        {
            //printf("ai == ai for %u and %u\n", x.ai, y.ai);
            //printf("between price %d\n", (x.price > y.price) - (x.price < y.price));
            return (x.price > y.price) - (x.price < y.price);
        }
        else
        {
            //printf("between a %d\n", (x.ai > y.ai) - (x.ai < y.ai));
            return (x.ai < y.ai) - (x.ai > y.ai);
        }
    }
    else
    {
        //printf("between p %d\n", (x.pi > y.pi) - (x.pi < y.pi));
        return (x.pi < y.pi) - (x.pi > y.pi);
    }
}

int main()
{
    int count = 0;
    scanf("%d", &count);
    //Item * items = malloc(count * sizeof(Item));
    Item items[N] = {};
    input(items, count);

    qsort(items, count, sizeof(Item), cmp);
    //printf("-----------------\n");
    print(items, count);

    //free(items);
    return 0;
}