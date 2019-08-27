#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main()
{
    int cash;
    float a = 0;
    do
    {
        a = get_float("Change owed: ");
        cash = round(a * 100);
    }while (cash >= 100 || cash <= 0);
    
    printf("25¢ - %i\n10¢ - %i\n 5¢ - %i\n 1¢ - %i\n%i coin(s)\n", cash/25, (cash - 25*(cash/25))/10, (cash - 25*(cash/25) - 10*((cash - 25*(cash/25))/10))/5, (cash - 25*(cash/25) - 10*((cash - 25*(cash/25))/10) - 5*((cash - 25*(cash/25) - 10*((cash - 25*(cash/25))/10))/5)), cash/25 + (cash - 25*(cash/25))/10 + (cash - 25*(cash/25) - 10*((cash - 25*(cash/25))/10))/5 + (cash - 25*(cash/25) - 10*((cash - 25*(cash/25))/10) - 5*((cash - 25*(cash/25) - 10*((cash - 25*(cash/25))/10))/5)));
}   