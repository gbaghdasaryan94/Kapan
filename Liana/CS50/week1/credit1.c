
#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main ()
{
    int i1, i2, k2, digit, sum ;
    long  cc, card;
    do
   {
      cc = get_long ("Give me a positive card number:" );
   }
    while (cc <=0);

    printf("%li\n", cc);
    i2=0;
    i1=0;
    k2=0;
    digit = 1; 
    card=cc;
    while (cc > 0)
         {
           i1 = i1 + cc % (10);
                                               // printf ("i1=%i\n", i1);
           cc= ((cc - cc % (10)) / 10);
           if (cc>0)
               digit=digit + 1;                      // printf ("cc=%li\n", cc);
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
          if (cc>0)
               digit=digit + 1;                 //  printf ("cc=%li\n", cc);
         }
         sum=i2+i1;
         printf ("sum=%i\n", sum);
         printf ("number of card digits= %i\n", digit);

         if ((sum % (10) == 0) && (digit == 15))
            {
              if ((card / pow(10,13) == 34) ||  (card / pow(10,13) == 37))
                {
                  printf("Amex card");
                }
            }
          
         if ((sum % (10) == 0) && (digit == 16))
            {
              if ((card / pow(10,14) == 51) ||  (card / pow(10,14) == 52) || (card / pow(10,14) == 53) || (card / pow(10,14) == 54) || (card / pow(10,14) == 55))
                {
                  printf("Master card");
                }
            }
         if ((sum % (10) == 0) && (digit == 13))
            {
              if (card / pow(10,12) == 4) 
                 {
                   printf("Visa card");
                 }
              }

         if ((sum % (10) == 0) && (digit == 16))  
            {
              printf ("card is %li\n", card);  
              if (card / pow(10,15) == 4) 
            {
              printf("Visa card\n");
            }
}   

             //else
            // {
              // printf ("card is invalid");
           //  }

}
