#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char * a;           // number is a[0]*10^0 + a[1]*10^1 + ..+ a[n]*10^n
    unsigned int n;     // наибольшая степень десяти
    unsigned int size;  // размер выделенной динамической памяти в а
}Decimal;

void elong_add (const Decimal * a, const Decimal * b, Decimal * res)
{
    res->n = a->n > b->n? a->n: b->n;
    printf("res n = %u, a n = %u, b n = %u\n", res->n, a->n, b->n);
    res->size = a->size > b->size? a->size: b->size;  
    res->a = calloc(res->size, sizeof(int));

    for(unsigned i = 0; i <= a->n || i <= b->n; i++)
    {
        unsigned to_add = (i <= a->n? a->a[i]: 0) + (i <= b->n? b->a[i]: 0);
        printf("for i = %u to add %u\n", i, to_add);
        res->a[i] += to_add%10;
        printf("res [%u] = %u\n", i, res->a[i]);
        res->a[i+1] += to_add/10;
        printf("res [%u] = %u\n", i+1, res->a[i+1]);

        if(i == b->n && res->a[i+1] > 0)
        {
            printf("res[%u] = %u, added to n\n", i+1, res->a[i+1]);
            (res->n)++;
        }
        printf("------------------\n");
    }

    return;
}

void elong_print(Decimal x)
{
    for(int i = x.n; i >= 0; i--)
        {
            printf("%d", x.a[i]);
        }
    printf("\n");
    return;
}

void elong_set_int(Decimal * px, unsigned int number)
{
    if (number == 0){       // 0*10**0
        px->size = 1;
        px->n = 0;
        px->a = malloc(px->size);
        px->a[0] = 0;
        return;
    } // number точно меньше 10 в 100, выделим память с запасом
    px->size = 100;
    px->a = malloc(px->size);

    for(px->n = 0; number > 0; px->n++){
        px->a[px->n] = number % 10;
        number /= 10;
    }
    px->n --;
    // выделим памяти точно под хранение числа
    px->size = px->n + 1;
    px->a = realloc(px->a, px->size);
}

void elong_destroy(Decimal * px)
{
    free(px->a);        // освобождаем желтый массив с цифрами
}

int main(){
    Decimal a;
    Decimal b;
    Decimal res; 

    elong_set_int(&a, 1234567890);    // 147
    elong_set_int(&b, 1234567890);     // 13

    elong_add(&a, &b, &res);   // res = a+b = 147+13 = 160

    elong_print(res);          // print 160

    elong_destroy(&a);
    elong_destroy(&b);
    elong_destroy(&res);

    return 0;
}