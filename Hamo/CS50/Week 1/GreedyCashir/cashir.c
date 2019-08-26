#include <cs50.h>
#include <stdio.h>

int main(){

    int coins[]  = {50,25,10,5,1};
    int quantity[]={0,0,0,0,0};
    int total=0;
    float sum;
    int length = 0;
    int n;

    do{
        sum=get_float("How much change is owed?\n");
    } while(!sum);
    sum=sum*100;

   n = (int)sum;


    length = sizeof(coins)/ sizeof(coins[0]) ;



    for(int i=0; i<length;i++){
        while(n>=coins[i]){
            n=n-coins[i];
            quantity[i]++;
        }
    }



    for(int i = 0; i < length; i++) {
        if(quantity[i]>0){
            printf("%d cent = %d pcs\n", coins[i],quantity[i]);
            total+=quantity[i];
        }
    }
        printf("\n");
        printf("total = %d coins\n",total );
        printf("\n");
    return 0;
}