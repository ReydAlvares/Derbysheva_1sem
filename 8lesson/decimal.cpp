#include <stdio.h>

int period(int ostatok[], int del_ost[], int chisl, int *length);
int compare(int ostatok[], int i);

int main()
{
    int chislitel = 0, znamenatel = 0, length = 0;
    int ostatok_deleniya[100] = {0}, delenie_ostatka[100] = {0};

    scanf("%d%d", &chislitel, &znamenatel);
    ostatok_deleniya[0] = (chislitel % znamenatel) * 10;

    int period_begining = period(ostatok_deleniya, delenie_ostatka, znamenatel, &length);

    if(period_begining == 0) 
    {
        printf("0,(");
        for(int i = 0; i < length; i++)
        {
            printf("%d", delenie_ostatka[i]);
        }
        printf(")\n");
    }
    else
    {
        printf("0,");
        for(int i = 0; i < period_begining; i++)
        {
            printf("%d", delenie_ostatka[i]);
        }
        printf("(");
        for(int i = period_begining; i < length; i++)
            printf("%d", delenie_ostatka[i]);
        printf(")\n");
    }

    return 0;
}

int period(int ostatok[], int del_ost[], int znam, int *length)
{
    int comp = 0;
    do
    {
        del_ost[*length] = ostatok[*length]/znam;
        ostatok[(*length)+1] = (ostatok[*length] % znam) * 10;
        (*length)++;
        comp = compare(ostatok, *length);
    }
    while(comp < 0);

    return comp; 
}

int compare(int ostatok[], int i)
{
    for(int j = 0; j < i; j++)
    {
        if(ostatok[i] == ostatok[j])
            return j;
    }

    return -1;
}