#include <stdio.h>
#include <cs50.h>
int main(void)
{
    long number1 = get_long("Give me your card number please  ");
    
    //4033190012565448
    long number = number1;
    int i,j,
    sum = 0;
    
    for(i = 0; i < 8; i++) {
        j = number % 100;
        j = j / 10;
        j *= 2;
        number = number / 100;
            
            while(j > 0) {
                sum += j % 10;
                j = j / 10;
            }
    }
       
    for(i = 0; i < 8; i++) {
        sum += number1 % 10;
        number1 = number1 / 100;
    }
        
    if(sum % 10 == 0) { printf("card is valid \n"); }
    else { printf("card is invalid \n"); }
}