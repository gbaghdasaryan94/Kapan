#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <math.h>

int main()

{
   string s1="A4", s2="A)4";
   int c=strcmp(s1, s2);
   printf("%i\n", c);
}