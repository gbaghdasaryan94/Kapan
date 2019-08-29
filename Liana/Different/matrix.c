#include  <stdio.h>
#include <cs50.h>


int main(void)
{
    int i,j,n ;
    n = get_int ("n=");
    for (i=0; i< (n+1); i++)
       {
           for (j=0; j< (n+1); j++ )
               {
                printf("%i ", (i*10)+j);
             } 
       printf ("\n" );
       }           
                   
                 
}