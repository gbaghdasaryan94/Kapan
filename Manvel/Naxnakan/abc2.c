#include <stdio.h>
#include <cs50.h>

int main(void){
int i,j;

    for(i=0;i<10;i++){

        for (j=10-i;j>=0;j--)
            {
            printf("#");
            }
            printf("\n");
    }
    
}