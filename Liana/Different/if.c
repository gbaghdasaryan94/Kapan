#include  <stdio.h>
#include <cs50.h>


int main(void)
{
    int n;
    n = get_int("number:");
    if (n % 2 ==  1)
           printf("number is odd\n");
           else 
                if (n == 0)
                printf ("number is zero\n");
                   else 
                   printf ("number is even\n");
                 
}

       