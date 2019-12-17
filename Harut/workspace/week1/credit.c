#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

long mypow();
int main(void)
{
    long c = get_long("Credit Card: ");
    int t, t2, s = 0, s2 = 0;

    for (int i = 1; i < 17; i += 2)
    {
        t2 = ((c % mypow(10, i + 1) - c % mypow(10, i)) / mypow(10, i)) * 2;
        t = (c % mypow(10, i) - c % mypow(10, i - 1)) / mypow(10, i - 1);

        if (t2 > 9)
        {
            t2 = t2 / 10 + t2 % 10;
        }

        s2 += t2;
        s += t;
    }

    if (((s + s2) % 10 == 0) && ((c / mypow(10, 13) == 34) || (c / mypow(10, 13) == 37)))
    {
        printf("AMEX\n");
    }

    else if (((s + s2) % 10 == 0) && ((c / mypow(10, 14) == 51) || (c / mypow(10, 14) == 52) ||
                                      (c / mypow(10, 14) == 53) || (c / mypow(10, 14) == 54) ||
                                      (c / mypow(10, 14) == 55)))
    {
        printf("MASTERCARD\n");
    }

    else if (((s + s2) % 10 == 0) && ((c / mypow(10, 12) == 4) || (c / mypow(10, 15) == 4)))
    {
        printf("VISA\n");
    }

    else
    {
        printf("INVALID\n");
    }
}

//____________________________________________
//mypow function-y hashvum e x-i n astichan

long mypow(int x, int n)
{
    long number = 1;

    for (int i = 0; i < n; i++)
    {
        number *= x;
    }

    return (number);
}
