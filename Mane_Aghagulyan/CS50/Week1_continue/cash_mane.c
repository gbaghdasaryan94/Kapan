#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(){
    float coin_f ;
    int count=0, count1, coin_i;

    do
    {
        coin_f=get_float("Input dollars and cents ");
    } while (coin_f<0);
    
    coin_i=round(coin_f*100);
    printf("cents %i \n", coin_i);
    
    count1=coin_i /25;
    printf("25 cent %i \n", count1);
    count +=count1;
    coin_i= coin_i- count1*25;
    printf("Cash %i \n", coin_i);

    count1=coin_i /10;
    count +=count1;
    printf("10 cent %i \n", count1);
    coin_i= coin_i- count1*10;
    printf("Cash %i \n", coin_i);

    count1=coin_i /5;
    count +=count1;
    printf("5 cent %i \n", count1);
    coin_i= coin_i-count1*5;
    printf("Cash %i \n", coin_i);

    count=count+coin_i;
    
    printf("Coins number %i \n", count);
    return 0;
}

