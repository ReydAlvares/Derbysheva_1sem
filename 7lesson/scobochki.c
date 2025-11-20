#include <stdio.h>

int main()
{
    int numb1 = 0, numb2 = 0, c = 0;
    char* answer = " ";
    while((c = getchar()) != EOF && c != '\n')
    {
        if(numb2 - numb1 == 1)
        {
            answer = "NO";
            break;
        }
        if(c == '(')
        {
            numb1++;
        }
        else if(c == ')')
        {
            numb2++;
        }
        if(numb1 == numb2)
            answer = "YES";
        else
            answer = "NO";
    }

    printf("%s\n", answer);
    return 0;
}