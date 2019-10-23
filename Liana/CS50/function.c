#include <stdio.h>
#include <cs50.h>

int sum(int n)
{
int s =0;
for(int i=0; i<=n; i++)
         s = s + i;
    
     return s;
}
 bool parz (int);
 int main ()
 {
     int n = get_int ("give me number");
     printf("%i\n", sum(n));
     if (parz (n))
     printf("n is parz");
 }

bool parz (int a)
{
  
  for(int i=2; i<a/2; i++)
      {
      if (a%i ==0)
      return false;}
      return true;  
}      