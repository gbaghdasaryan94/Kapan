+
#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>

int main(){
    long CR_Card = get_long("Insert credit card number :");
    int  credit = CR_Card;
    string CardName="fail";
    
    int sum1 =0, sum2 =0, count =0, sum;
    
    while (credit > 0)
    {
        sum1 += credit%10;
        if(credit>0){
            credit = credit/10;
            count++;}
        else break;
        
        sum2 += credit%10;
        if(credit>0){
            credit = credit/10;
            count++;
        }
        else break;
    }

    if(count%2 == 1)
    {
        sum = sum1*2 + sum2;
    }
    else {
        sum = sum2*2 + sum1;        
    }
        printf("%i\n", count);

        printf("%i\n", sum1);
        printf("%i\n", sum2);
        printf("%i\n", sum);


    if(count == 15 && (CR_Card/pow(10,13)==34 ||CR_Card/pow(10,13)==37))   
        CardName = "AMEX";
    if(count== 16 && (CR_Card/pow(10,14)>= 51 && CR_Card/pow(10,14)<= 55))
        CardName = "MasterCard";
    if((count == 13 && CR_Card/pow(10,11)== 4)|| (count == 16 && CR_Card/pow(10,14)== 4))
        CardName = "VISA";


    printf("%s\n", CardName);


}