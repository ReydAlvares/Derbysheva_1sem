#include <stdio.h>
#define MAX_STAFFS 100

void resalary(int a[], int* boss_money, int j, int staff);
int main()
{
    int staffs = 0, 
        boss_money = 0, 
        staff_money[MAX_STAFFS] = {};
    
    do
    {
        scanf("%d", &staffs);
    } 
    while (staffs <= 1 && staffs >= 100);

    for(int i = 0; i < staffs; i++)
    {
        scanf("%d", &staff_money[i]);
    }

    for(int j = 0; j <= staffs-1; j++)
    {
        if(j == staffs - 1)
        {
            printf("[%d] = %d, [%d] %d\n", staffs-1, staff_money[staffs-1], 0, staff_money[0]);
            resalary(staff_money, &boss_money, j, staffs-1);
            for(int k = 0; k < staffs-1; k++)
            {
                if(staff_money[k] != staff_money[k+1] || staff_money[0] != staff_money[staffs-1] )
                {
                    j = -1;
                    continue;
                }
            }
            printf("---------------------------------------------\n");
        }
        else if(j != staffs - 1 && staff_money[j] != staff_money[j+1])
        {
            printf("[%d] = %d, [%d] %d\n", j, staff_money[j], j+1, staff_money[j+1]);
            resalary(staff_money, &boss_money, j, staffs);
            printf("---------------------------------------------\n");
        }
        else
        {
            continue;
        }
    }
    
    printf("%d %d\n", boss_money, staff_money[0]);

    return 0;
}

void resalary(int a[], int* boss_money, int j, int staff)
{
    if(j != staff)
    {
        int buf1 = a[j], buf2 = a[j+1];
        if((buf1 + buf2)%2 == 0)
        {
            a[j] = (buf1 + buf2)/2;
            a[j+1] = a[j];
            printf("****[%d] = %d, [%d] %d\n", j, a[j], j+1, a[j+1]);
        }
        else
        {
            a[j] = (buf1 + buf2 - 1 )/2;
            a[j+1] = a[j];
            (*boss_money)++;
            printf("****[%d] = %d, [%d] %d, boss+%d\n", j, a[j], j+1, a[j+1], *boss_money);
        }
    }
    else
    {
        int buf1 = a[staff], buf2 = a[0];
        if((buf1 + buf2)%2 == 0)
        {
            a[staff] = (buf1 + buf2)/2;                
            a[0] = a[staff];
            printf("****[%d] = %d, [%d] %d\n", j, a[j], 0, a[0]);
        }
       else
        {
            a[staff] = (buf1 + buf2 - 1)/2;
            a[0] = a[staff];
            (*boss_money)++;
            printf("****[%d] = %d, [%d] %d\n, boss+%d\n", j, a[j], 0, a[0], *boss_money);
        }
    }
    return;
}