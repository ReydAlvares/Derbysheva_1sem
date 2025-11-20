#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char *dig;  // массив для хранения числа:
                // a[0] * 100^0 + a[1] * 100^1 + .. + a[n - 1] * 100^(n-1)
    int n;      // размер числа в разрядах
    char sign;  // знак числа
} LongN;

void print_long(LongN* number)
{
    printf("%s", number->sign == '0'? "+ ": "- ");

    for(int i = number->n - 1; i >= 0; i--)
    {
        printf("%d ", number->dig[i]);
    }
    printf("\n");
}

LongN getLongN(char * s)
{
    LongN numb;
    numb.dig = malloc(100*sizeof(char));

    numb.sign = s[0] == '-'? '1': '0';

    //printf("sign = %c\n", numb.sign);

    int s_len = (s[0] == '-' || s[0] == '+')? strlen(s + 1): strlen(s);

    //printf("length s = %d\n", s_len);

    numb.n = s_len%2 == 0? s_len/2: s_len/2 + 1;

    //printf("n = %d\n", numb.n);

    for(int i = 0; i < (s_len%2 == 0? numb.n: numb.n - 1); i++)
    {
        numb.dig[i] = s[(s[0] == '-' || s[0] == '+')? s_len - 2*i: s_len - 2*i - 1] - 48 + (s[(s[0] == '-' || s[0] == '+')? s_len - 2*i - 1: s_len - 2*i - 2] - 48) * 10;
        //printf("numb.dig[%d] = %d, s[%d] = %d, s[%d] = %d\n", i, numb.dig[i], s_len - 2*i - 1, s[s_len - 2*i - 1] - 48, s_len - 2*i - 2, (s[s_len - 2*i - 2] - 48) * 10);   
    }

    if(s_len%2 != 0)
    {
        numb.dig[numb.n - 1] = (s[0] == '-' || s[0] == '+')? s[1] - 48: s[0] - 48;
        //printf("num.dig[%d] = %d\n", numb.n - 1, numb.dig[numb.n - 1]);
    } 

    return numb;
}

int main()
{
    LongN x = getLongN("4327429874389171");

    print_long(&x);
    free(x.dig);
    return 0;
}