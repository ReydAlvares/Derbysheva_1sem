#include <stdio.h>

int main()
{
    int price = 0, delta = 0, money = 0, wday = 0;
    scanf("%d%d%d", &price, &delta, &money);

    while(money >= price)
        {
            money -= price;
            wday++;
            if(wday%7 == 0)
                {
                    price += delta;
                }
        }
    printf("%d", wday);
    return 0;
}