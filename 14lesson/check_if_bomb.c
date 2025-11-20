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
    size_t lensrc = strlen(src) - 1;
    size_t count_bombs = 0;
    char * bomb_ptr = 0;
    char * s_check = (char*)src;

    char * d = malloc(lensrc * sizeof(char));
    char * d_check = d;

    if(d_check != 0)
    {
        printf("Allocated memory = %zu\n", lensrc);
        printf("%s\n", src);
    }
    else
    {
        return "ERROR: couldn't allocate memory\n";
    }

    while((bomb_ptr = strstr(s_check, "bomb")) != 0)
    {
        printf("bomb_adress = %p\n", bomb_ptr);

        int n = bomb_ptr - s_check;

        printf("between = %d\n", n);

        count_bombs++;
        strncpy(d_check, s_check, n);

        printf("d = %s, d_check = %s\n", d, d_check);

        if((d = realloc(d, (lensrc + 7 * count_bombs)*sizeof(char))) != 0)
            printf("Reallocated memory = %zu\n", (lensrc + 7 * count_bombs)*sizeof(char));

        d_check += n;
        printf("d = %s, d_check = %s\n", d, d_check);

        strcpy(d_check, "watermelon");

        printf("%s, length - %zu\n", d, lensrc + 7 * count_bombs);
        printf("added = %s\n", d_check);

        s_check += n + strlen("bomb"); 
        printf("s_check = %s\n", s_check);

        d_check += strlen("watermelon");
    }

    strcpy(d_check, s_check);

    printf("length - %zu\n", strlen(d));
    d[strlen(d) - 1] = '\0';
    return d;
}