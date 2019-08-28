#include  <stdio.h>
#include <cs50.h>

int main(void)

{
 int n, i, j, k;    
do 
   {
 n = get_int ("Give me a positive number:" );
   }
while (n <=0);
    
   for (i=0; i<n; i++)
   { 
      for (k=0; k<(n-i-1); k++)
      {
         printf (" ");
      }
      for (j=0; j<=i; j++)
      {
         printf ("#");
      }  
      printf("  "); 

       for (j=0; j<=i; j++)
      {
         printf ("#");
      }  
    printf("\n");
    }
}