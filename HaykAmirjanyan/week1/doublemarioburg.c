#include <stdio.h>
#include <cs50.h>
int main(void) {     
    int heigth = get_int("write int number  ");     
    int i, j;     
    for(i = 0; i < heigth; i++) {         
        for(j = 0; j < heigth; j++) {             
            if(i + j < heigth - 1) {                 
                printf(" ");
                } else {                 
                    printf("#");            
                    }
                    }      printf("  ");  
                for(j = 0; j < heigth; j++){            
                    if(i + j > heigth - 2 )             
                    printf("#");         }        
                    printf("\n");    
                    }    
                    
                }