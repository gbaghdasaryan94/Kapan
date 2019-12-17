#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main()
{
    int coins;

    do
    {
        coins = round(get_float("Change owed: ") * 100);
    }
    while (coins <= 0);
    
    printf("%i\n", coins / 25 + (coins % 25) / 10 + ((coins % 25) % 10) / 5 + ((coins % 25) % 10) % 5);
}
