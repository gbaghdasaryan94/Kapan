#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    long credit = get_long("Enter the credit number: ");
    char str[17];
    //convert long to string
    sprintf(str, "%li", credit);
    int length = strlen(str);
    bool x = true;
    int sum2 = 0;

    while (credit > 0)
    {
        long temp;
        //get every last digit
        long tiv = credit % 10;

        if (!x)
        {
            tiv = 2 * tiv;
            temp = tiv / 10 + tiv % 10;
            sum2 = sum2 + temp;
            x = true;
        }
        else
        {
            sum2 = sum2 + tiv;
            x = false;
        }
        credit = credit / 10;
    }

    if (sum2 % 10 == 0)
    {
        if (length == 15 && str[0] == '3' && (str[1] == '4' || str[1] == '7'))
        {
            printf("AMEX\n");
        }
        else if ((length == 13 || length == 16) && (str[0] == '4' || str[0] == '2'))
        {
            printf("VISA\n");
        }
        else if (length == 16 && str[0] == '5' &&  str[1] <= '5')
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }

    }
    else
    {
        printf("INVALID\n");
    }
}
