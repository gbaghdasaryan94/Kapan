#include <stdio.h>
int main(void)
{
    int heigth = 5;
    int i, j;
    for ( i = 0; i < heigth; i++ ) {
        for ( j = 0; j < heigth; j++) {
            if( i + j  <  heigth - 1) {
                printf(" ");
            } else {
                printf("#");
            }
        }  
        printf("\n");
       
    } 
}