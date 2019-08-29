#include  <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)

{ 
  int i,n;  
  string s = get_string("input:  ");
  printf ("output\n");
  for (i=0, n=strlen(s); i < n; i++)
  {
      printf ("%c %i\n", s[i], (int) s[i]);
  } 
}