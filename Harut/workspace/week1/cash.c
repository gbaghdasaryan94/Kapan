#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main()
{
    float d;

    do
    {
        d = get_float("dollar: ");
    }

    while (d < 0);

    int c = round(d * 100);
    int q = c / 25 + c % 25 / 10 + c % 25 % 10 / 5 + c % 25 % 10 % 5 / 1;
    printf("%i\n", q);
}