#include <stdio.h>
#include <cs50.h>

int main (void){
    long credit = get_long("Enter the credit number: ");
    bool x= true;
    int sum2=0;

while (credit>0){
    long temp;
    long tiv = credit%10;
    if (!x){
             tiv = 2*tiv;
             temp = tiv/10+tiv%10;
             sum2 = sum2 + temp;
             x = true;
    }
    else
    {
        sum2 = sum2+tiv;
        x=false;
    }
    credit = credit/10;

}
if (sum2%10==0){
    printf("valid Card! ");
}else
printf("Card is invalid!");

}