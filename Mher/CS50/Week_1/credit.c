#include<stdio.h>
#include<cs50.h>
#include <math.h>

int main(void)
{
    long int n = get_long("Cart: ");
    long int save = n;
    int a = 0;
    
    while (n > 0)
    {
        a += n % 10;
        n = n / 10;
    
        if (n % 10 * 2 > 9)
        {
            a = a + ((n % 10 * 2) % 10) + 1;
            n = n / 10;
        }
        else
        {
            a += n % 10 * 2;
            n = n / 10;
        }
    }

    if (a % 10 == 0)
    {
        if (save / 10000000000000 == 34 || save / 10000000000000 == 37)
        {
            printf("AMEX\n");
        }
        else if (save / 1000000000000000 == 4 || save / 1000000000000000 == 4)
        {
            printf("VISA\n");
        }
        else if (save / 100000000000000 > 50 && save / 100000000000000 < 56)
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