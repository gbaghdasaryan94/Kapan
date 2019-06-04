//use the fewest number of coins possible to make the change

#include <stdio.h>

int main(void)
{
    int m = 118,

    q = 25, d = 10, n = 5, p = 1,
    cq, cd, cn, cp, c;

    for (int i=1; i<100; i++)
    {
        m=m-q;
         if (m>=0)
         {
        cq=i;
          }          
          else m=m+q;
    }

      for (int i=1; i<100; i++)
    {
        m=m-d;
         if (m>=0)
         {
        cd=i;
          }
          else m=m+d;
    }

  for (int i=1; i<100; i++)
    {
        m=m-n;
         if (m>=0)
         {
        cn=i;
          }
          else m=m+n;
    }

      for (int i=1; i<100; i++)
    {
        m=m-p;
         if (m>=0)
         {
        cp=i;
          }
    }
c = cq+cd+cn+cp;
printf("%i\n", c);
}
