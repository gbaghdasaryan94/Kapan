#include <stdio.h>

int main(void){
    int height=6;
    for (int i=1; i<=height; i++){
        for (int n=i; n<height; n++){
            printf(" ");
        }
        for (int n=1; n<=i; n++){
            printf("#");
        }
        printf("    ");
        for (int n=1; n<=i; n++){
            printf("#");
        }
        
        printf("\n");
    }
    
    
}