#include <stdio.h>
#include <cs50.h>

int main ()
{
    int i1, i2 ;
    long  cc = get_long("Enter a long : ");
    printf("%li\n", cc);
    i2=0;
    i1=0;
    while (cc >0)
         { 
           i1 = i1 + cc % (10);
           printf ("i1=%i\n", i1);
           cc= (int) (cc/10);
           printf ("cc=%li\n", cc); 
           i2=i2+2*(cc % (10));
           printf ("i2=%i\n", i2 );
          
         }
}