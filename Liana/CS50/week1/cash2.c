#include  <stdio.h>
#include <cs50.h>
#include  <math.h>

int main(void)
{
    double n;
    int c,k;
    c=0;
    k=0;
    do 
    {
    n=get_float("give me a positive number: ");     
    }
    while (n <= 0); 
    printf ("n=%f\n", n);
    n = (n*100); 
    n = round (n);
    printf ("n=%f\n", n);
    k= (int) n;
    printf ("k=%i\n", k); 

    if (k >= 25)
       {
        c=k/25;
        k = k % 25;
       }
    if (k >=10)
       {
        c=c+k/10;
        k=k % 10;
    }
    if (k>=5)
        {
         c=c+k/5;
         k=k % 5;   
        }
    if (k>=1)
        {
         c=c+k/1;
         k=k % 1;   
        }    
    printf("%i\n", c);
}