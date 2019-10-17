#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int main(void)
{
    long number1 = get_long("Take me your card number: ");

    char tmp[17];
    sprintf(tmp, "%li", number1);
    int len = strlen(tmp);

    long number = 0;
    number += number1;
    int j,
        sum = 0;

    while (number > 0)
    {
        j = number % 100;
        j = j / 10;
        j *= 2;
        number = number / 100;
        while (j > 0)
        {
            sum += j % 10;
            j = j / 10;
        }
    }

    while (number1 > 0)
    {
        sum += number1 % 10;
        number1 = number1 / 100;
    }
    if (sum % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    if (len == 16 && tmp[0] == 53 && tmp[1] < 54)
    {
        printf("MASTERCARD\n");
    }

    if (len == 15 && tmp[0] == 51 && (tmp[1] == 52 || tmp[1] == 55))
    {
        printf("AMEX\n");
    }

    if ((len == 16 || len == 13) && tmp[0] == '4')
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
