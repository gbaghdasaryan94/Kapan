#include <cs50.h>
#include <stdio.h>

int main (void){
    int number = 890;
    int q=0;

    q=q+number/25;
    number=number%25;

    q=q+number/10;
    number=number%10;

    q=q+number/5;
    number=number%5;

    q=q+number/1;
    number=number%1;

    printf(q);

}
