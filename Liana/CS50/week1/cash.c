#include  <stdio.h>
#include <cs50.h>

int main(void)
{
    double n;
    int c;
    c=0;
    do 
    {
    n=get_double("give me a positive number: ");     
    }
    while (n <= 0); 
    // n = n -(int)n;
    //  printf ("%2f\n", n); 

    while (n >= 0.25)
    {
    c=c+1;
    n=n-0.25;
    printf ("%f\n", n);
    }   
    while (n>=0.1)
    {
    c=c+1;
    n=n-0.1;    
    printf ("%f\n", n);
    }
    while (n>= 0.05)
    {
    c=c+1;
    n=n-0.05;  
    printf ("%f\n", n);  
    }
    while (n>=0.0099)
    {
    c=c+1;
    n=n-0.01;    
    printf ("%f\n", n); 
    }
    printf ("%i\n",c);
}