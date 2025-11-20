#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char * a;           // number is a[0]*10^0 + a[1]*10^1 + ..+ a[n]*10^n
    unsigned int n;     // наибольшая степень десяти
    unsigned int size;  // размер выделенной динамической памяти в а
}Decimal;

Decimal * elong_add (const Decimal * a, const Decimal * b)
{
    Decimal * res = malloc(sizeof(Decimal));
    res->n = a->n > b->n? a->n: b->n;
                                //printf("res n = %u, a n = %u, b n = %u\n", res->n, a->n, b->n);
    res->size = a->size > b->size? a->size: b->size;  
    res->a = calloc(res->size, sizeof(int));

    for(unsigned i = 0; i <= a->n || i <= b->n; i++)
    {
        unsigned to_add = (i <= a->n? a->a[i]: 0) + (i <= b->n? b->a[i]: 0) + (i == 0? 0: res->a[i]);
                                //printf("for i = %u to add %u\n", i, to_add);
        res->a[i] = to_add%10;
                                //printf("res [%u] = %u\n", i, res->a[i]);
        res->a[i+1] = to_add/10;
                                //printf("res [%u] = %u\n", i+1, res->a[i+1]);

        if(res->n == i && res->a[i+1] > 0)
        {
                                //printf("res[%u] = %u, added to n\n", i+1, res->a[i+1]);
            (res->n)++;
        }
                                //printf("------------------\n");
    }

    return res;
}

void elong_print(Decimal * x)
{
    for(int i = x->n; i >= 0; i--)
        {
            printf("%d", x->a[i]);
        }
    printf("\n");
    return;
}

Decimal * elong_set_int(unsigned int number)
{
                            // сначала выделим память под саму структуру (фиолетовый прямоугольник)
    Decimal * px = malloc(sizeof(Decimal));

    if (number == 0){       // 0*10**0
        px->size = 1;
        px->n = 0;
        px->a = malloc(px->size);
        px->a[0] = 0;
        return px;
    }
                            // number точно меньше 10 в 100, выделим память с запасом
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
    return px;
}

void elong_destroy(Decimal * px)
{
    free(px->a);        // освобождаем желтый массив с цифрами
    free(px);           // освобождаем фиолетовый прямогольник, саму структуру
}

int main(){
    Decimal * a;
    Decimal * b;
    Decimal * res;

    a = elong_set_int(147);    // 147
    b = elong_set_int(13);     // 13

    res = elong_add(a, b);     // res = a+b = 147+13 = 160

    elong_print(res);          // print 160

    elong_destroy(a);
    elong_destroy(b);
    elong_destroy(res);

    return 0;
}