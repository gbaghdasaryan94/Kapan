#include <cs50.h>
#include <stdio.h>

int main(){

int n;

do{
    n=get_int("Please enter pyramide height. More thane 0, less than 23 \n");
} while( n<1 || n>23);


for (int i=0; i<n;i++){
    for(int j=n-1; j>=0;j--){
        if(j>i){
            printf(".");
        } else{
            printf("#");
        }
    }

    printf(" ");

    for(int j=0; j<=i;j++){
       
            printf("#");
        
    }

    printf("\n");
}

    return 0;
}