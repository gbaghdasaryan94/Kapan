

// Compares two strings' addresses

#include <cs50.h>
#include <stdio.h>

int main(void)
{
   int x=20; 
   int* pi = &x;
   int y = *pi; 
   printf("x = %d\n", x); 
   printf("y = %d\n", y);     
}
cd