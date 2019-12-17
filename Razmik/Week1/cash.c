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
    }
    while (cash <= 0);
    printf("%i\n", cash / 25 + (cash % 25) / 10 + (cash % 25 % 10) / 5 + cash % 5);
}