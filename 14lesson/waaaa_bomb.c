#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 1000

char * replace(const char * src);
int main()
{
    char s[N];   // нужно объявить переменную - место для читаемой строки
    char * d = NULL;    // указатель на динамический массив, память еще не выделена

    while (NULL != fgets(s, N, stdin)) {  // пока можем прочитать строку
        d = replace(s);                   // тут память выделяем
        printf("+++%s+++\n", d);
        free(d);                          // тут память освобождаем
    }
    return 0;
}

char * replace(const char * src)
{
    size_t srclen = strlen(src);
    size_t count_bomb = 0;
    char * bomb_ptr = 0;
    char * s_check = (char*)src;

    s_check[srclen - 1] = '\0';
    printf("s_check - %s\n", s_check);

    char * d = malloc(srclen * sizeof(char));
    d[0] = '\0';

    if(d)
    {
        printf("Allocated %zu, d = %p\n", srclen, d);
    }
    while((bomb_ptr = strstr(s_check, "bomb")) != 0)
    {
        
        count_bomb++;
        printf("Started loop\n");
        size_t to_bomb = bomb_ptr - s_check;

        if((d = realloc(d, (strlen(src) + 6 * count_bomb) * sizeof(char))) != 0)
        {
            printf("Realloc %zu\n", strlen(src) + 6 * count_bomb);
        }
        printf("s_check - %s, to bomb = %zu\n", s_check, to_bomb);
        strncat(d, s_check, to_bomb);
        printf("d after strNcat - %s\n", d);

        strcat(d, "watermelon");

        s_check += strlen("bomb") + to_bomb;
    }

    strcat(d, s_check);
    printf("d - %s\n", d);
    d[strlen(d)] = '\0';

    return d;
}