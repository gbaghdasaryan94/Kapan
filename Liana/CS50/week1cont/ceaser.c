#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main ()

{
  string s = get_string ("input string: ");
  int n=strlen(s);
  int k;
  do
   {
      k = get_int ("Give me a positive key:" );
   }
while (k <=0);
  if (k>26)
    {
     k = k % 26;
     printf("new k = %i\n", k);
    }
  for (int i=0; i<n; i++)
    {
     if (s[i]>= 'a' && s[i]<= 'z')
        {
               if ((int)s[i] + k <=122)
                  {

                   printf ("%c", s[i]+k);
                  }
               if ((int)s[i]+k > 122)
                  {
                   printf ("%c", s[i]+k -'z'+'a'-1);
                  }
         }

    if (s[i]>= 'A' && s[i]<= 'Z')
       {

          if ((int)s[i] + k <= 90)
              {
               printf ("%c", s[i]+k);                                                        //printf ("%c %i ", s[i], (int) s[i]);
              }
          if ((int)s[i]+k > 90)
             {
             printf ("%c", s[i]+k-'Z' + 'A' -1);                                                             // printf ("%c %i ", s[i] -'Z' + 'A' -1, (int)s[i]-25);
             }
         }
    if (s[i]< 'A' || (s[i] >'Z' && s[i] < 'a') || s[i] > 'z' )      // for other symbols not to encrypt
       {
        printf ("%c", s[i]);
       }

    }

    printf("\n");
 }


