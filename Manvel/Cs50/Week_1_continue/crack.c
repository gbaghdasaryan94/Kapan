#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <crypt.h>
/*
int main(void)

{
int i;
int n=get_int ("mutq: ");
int s=0;
for ( i=0;i<n;i++)
{
    s=s+i;
}
    printf("%i\n",s);
}*/
int gumar(int);
int main(void)
{

   int m=get_int ("mutq: ");
   int final=gumar(m);
   printf("%i\n", final);
   printf("%i\n", gumar(15));
  printf("%i\n", gumar(10));
  printf("%i\n", gumar(6));
  printf("%i\n", gumar(125));
  printf("%i\n", gumar(7889));
  printf("%i\n", gumar(2));
}
int gumar(int n)

{   int s=0;
    for(int i=0;i<n;i++){
    s=s+i;
    }
    return s;
}