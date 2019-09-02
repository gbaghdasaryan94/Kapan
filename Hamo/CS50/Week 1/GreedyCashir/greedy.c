#include <cs50.h>
#include <stdio.h>

int main(){

    int coins[]  = {50,25,10,5,1};
    int quantity[]={0,0,0,0,0};
    int total=0;
    double sum;
    int length = 0;
    int n;

    do{
        sum=get_double("How much change is owed?\n");
    } while(!sum);
    //sum=sum*100;

   n = sum*100;


    length = sizeof(coins)/ sizeof(coins[0]) ;



    for(int i=0; i<length;i++){
        if(n>=coins[i]){            
            quantity[i]=quantity[i]+n/coins[i];
            n=n%coins[i];
        }
    }

    printf("\n");

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
