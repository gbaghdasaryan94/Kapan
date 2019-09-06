#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(){

int x;
x  = get_int ("ds");
switch(x)
{
case 1:
    printf("One!\n");
    break;
case 2:
printf("Two!\n");
    break;
case 3:
printf("Three!\n");
    break;
default:
printf("Sorry!\n");
    break;
}
}