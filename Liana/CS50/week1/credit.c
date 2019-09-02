#include <stdio.h>
#include <cs50.h>

int main ()
{
    int i1, i2, k2, sum ;
    long cc;
    do
   {
      cc = get_long ("Give me a positive card number:" );
   }
    while (cc <=0);

    printf("%li\n", cc);
    i2=0;
    i1=0;
    k2=0;
    while (cc > 0)
         {
           i1 = i1 + cc % (10);
                                               // printf ("i1=%i\n", i1);
           cc= ((cc - cc % (10)) / 10);
                                               // printf ("cc=%li\n", cc);
           k2=(2*(cc% (10)));
                                               // printf ("k2=%i\n", k2);
           if (k2>9)
              {
                 k2= ((k2%10) + (k2/10));
              }
                                               // printf ("k2=%i\n", k2);
           i2=i2+k2;
                                               // printf ("i2=%i\n", i2 );
          cc= ((cc - cc % (10)) / 10);
                                               //  printf ("cc=%li\n", cc);
         }
         sum=i2+i1;
         printf ("sum=%i\n", sum);
         if ((sum % (10)) == 0)
            {
               printf ("card is valid");
            }
            else
            {
               printf ("card is invalid");
            }


}