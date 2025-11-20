#include <stdio.h>

typedef struct{
    int h; // часы
    int min; // минуты (от 0 до 59)
}TicTac;

void check_time(TicTac * a, int q_min);
TicTac after(TicTac a, int min);
void forward(TicTac * me, TicTac a);
void backward(TicTac * me, TicTac a);
int isEqualTime(TicTac a, TicTac b);
void printTic(TicTac a);
int main(){
    TicTac a,b,c;
    int mk;

    scanf("%d:%d", &(a.h), &(a.min));
    scanf("%d", &mk);
    scanf("%d:%d", &(b.h), &(b.min));

    printf("equal: %d\n",isEqualTime(a,b));
    c = after(a, mk);
    printf("after: ");
    printTic(c);

    c = a;
    printf("forward: ");
    forward(&a, b);
    printTic(a);

    printf("backward: ");
    backward(&c, b);
    printTic(c);

    return 0;
}

void check_time(TicTac * a, int q_min)
{
    a -> h = (q_min/60)%12;
    a -> min = q_min%60;
    //формула проверки выхода за пределы циферблата (минуты + часы)
}

TicTac after(TicTac a, int min)
{
    int all_minutes = a.h * 60 + a.min;
    all_minutes += min;
    check_time(&a, all_minutes);
    return a;
}

void forward(TicTac * me, TicTac a)
{
    int all_me_min = (me->h) * 60 + me->min;
    int all_a_min = a.h * 60 + a.min;
    all_me_min += all_a_min;
    check_time(me, all_me_min);
}

void backward(TicTac * me, TicTac a)
{
   int all_me_min = (me->h) * 60 + me->min;
   int all_a_min = a.h * 60 + a.min;
   if(all_me_min <= all_a_min)
   {
        all_me_min += 720 - all_a_min;
   }
   else
   {
        all_me_min -= all_a_min;
   }
    check_time(me, all_me_min);
}

int isEqualTime(TicTac a, TicTac b)
{
    if(a.h == b.h && a.min == b.min)
        return 1;
    else
        return 0;
}

void printTic(TicTac a)
{
    printf("%02d:%02d\n", a.h, a.min);
}