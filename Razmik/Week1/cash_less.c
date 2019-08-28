#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    int cash;
    float a;
    do
    {
        a = get_float("Change owed: ");
        cash = round(a * 100);
    }while (cash <= 0);
    
    printf("25¢ - %i\n10¢ - %i\n 5¢ - %i\n 1¢ - %i\n%i coin(s)\n", cash/25, (cash%25)/10, (cash%25%10)/5, cash%25%10%5, cash/25+(cash%25)/10+(cash%25%10)/5+cash%25%10%5);
}   