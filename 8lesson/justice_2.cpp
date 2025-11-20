#include <stdio.h>
#define MAX_STAFFS 100

void resalary(int a[], int* boss_money, int j, int staff);
int main()
{
    int staffs     = 0, 
        boss_money = 0, 
        staff_money[MAX_STAFFS] = {};
    
    do
    {
        scanf("%d", &staffs);
    } 
    while (staffs <= 1 && staffs >= 100);

    for(int salary_index = 0; salary_index < staffs; salary_index++)
    {
        scanf("%d", &staff_money[salary_index]);
    }

    for(int salary_index = 0; salary_index <= staffs - 1; salary_index++) // TODO salary_index < staffs
    {
        if(salary_index == staffs - 1 && staff_money[staffs - 1] != staff_money[0])
        {
            printf("[%d] = %d, [%d] %d\n", staffs-1, staff_money[staffs - 1], 0, staff_money[0]);
            resalary(staff_money, &boss_money, salary_index, staffs-1);
            printf("---------------------------------------------\n");
        }
        else if(salary_index != staffs - 1 && staff_money[salary_index] != staff_money[salary_index+1])
        {
            printf("[%d] = %d, [%d] %d\n", salary_index, staff_money[salary_index], salary_index+1, staff_money[salary_index + 1]);
            resalary(staff_money, &boss_money, salary_index, staffs);
            printf("---------------------------------------------\n");
        }
        if(salary_index == staffs-1)
        {
            for(int extra_salary_index = 0; extra_salary_index < staffs-1; extra_salary_index++)
            {
                if(staff_money[extra_salary_index] != staff_money[extra_salary_index+1] || staff_money[0] != staff_money[staffs - 1] )
                {
                    salary_index = -1;
                    continue;
                }
            }
        }
        else
        {
            continue;
        }
    }
    
    printf("%d %d\n", boss_money, staff_money[0]);

    return 0;
}

void resalary(int a[], int* boss_money, int j, int staff) // TODO what the fuck is j???
{
    if(j != staff)
    {
        int buf1 = a[j], buf2 = a[j+1];
        if((buf1 + buf2)%2 == 0)
        {
            a[j] = (buf1 + buf2)/2;
            a[j+1] = a[j];
            printf("****[%d] = %d, [%d] %d\n", j, a[j], j+1, a[j+1]); // TODO where are spaces?
        }
        else
        {
            a[j] = (buf1 + buf2 - 1 )/2; // FIXME where are they?
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
    
    return; // TODO nahuya?
}