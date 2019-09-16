#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

bool check_sum(long card)
{
    int sum = 0;
    bool isTwo = false;

    while (card > 0)
    {
        int num = (int)(card % 10);
        if (isTwo)
        {
            num *= 2;
        }
        isTwo = !isTwo;

        sum += num / 10 + num % 10;
        card /= 10;
    }
    return (bool)!(sum % 10);
}

int main()
{
    long card = get_long("Number: "); 

    int len = floor(log10(card)) + 1;
    bool check = check_sum(card);
    char str[16];
    sprintf(str, "%li", card);
    string Message = "INVALID";

    if (len == 15 && check && str[0] == '3' && (str[1] == '4' || str[1] == '7'))
    {
        Message = "AMEX";
    }
    if (len == 16 && check && str[0] == '5' && (str[1] > '0' && str[1] < '6'))
    {
        Message = "MASTERCARD";
    }
    if ((len == 13 || len == 16) && check && str[0] == '4')
    {
        Message = "VISA";
    }
    
    printf("%s\n", Message);
} 