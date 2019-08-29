#include  <stdio.h>
#include <cs50.h>


int main(void)
{
    int n, i;
    i=0;
    for (n=100; n<1000; n++)
       {
       if (n % 3 ==  0)
           i=i+1; 
       }           
                   printf ("i=%i\n n=%i\n", i, n );
                 
}