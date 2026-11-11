#include <stdbool.h>
#include <stdio.h>

int main(void)
{
    // get day, month, year from user
    int day, month, year; 

    do 
    {
        printf("Year: ");
        scanf("%i", &year);
    }
    while (year < 1970);

    do
    {
        printf("Month: ");
        scanf("%i", &month);
    }
    while (month > 12 || month < 1);
    
    bool is_leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    int month_default[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (is_leap) {month_default[1] = 29;}

    do 
    {
        printf("Days: ");
        scanf("%i", &day);
    }
    while (day < 1 || day > (month_default[month - 1]));

    printf("%i--%i--%i\n", year, month, day);

    int Ydays = 0, Mdays = 0, Ddays = day - 1;

    for (int i = 1970; i < year; i++)
    {
        if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0))
        {
            Ydays += 366;
        }
        else
        {
            Ydays += 365;
        }
    }

    for (int i = month - 1; i > 0; i--)
    {
        Mdays += month_default[i - 1];
    }

    int total_days = Ydays + Mdays + Ddays;
    printf("Total days since 1970: %i\n", total_days);
}
