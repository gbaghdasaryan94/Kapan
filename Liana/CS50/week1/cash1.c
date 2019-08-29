#include  <stdio.h>
#include <cs50.h>

int main(void)
{
    double n;
    int c,k;
    c=0;
    do 
    {
    n=get_double("give me a positive number: ");     
    }
    while (n <= 0); 
    printf ("n=%f\n", n);
    k= n*100;
    printf ("k=%i\n", k); 

    while (k >= 25)
    {
    c=c+1;
    k=k-25;
    // printf ("%i\n", k);
    }   
    while (k>=10)
    {
    c=c+1;
    k=k-10;    
    // printf ("%i\n", k);
    }

    while (k>= 5)
    {
    c=c+1;
    k=k-5;  
    // printf ("%i\n", k);  
    }
    while (k>=1)
    {
    c=c+1;
    k=k-1;    
    // printf ("%i\n", k); 
    }
    printf ("%i\n", c);
}