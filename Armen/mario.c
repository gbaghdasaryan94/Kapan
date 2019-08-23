#include <stdio.h>
#include <cs50.h>
int main(void){
    int height=get_int("input height: ");
    for (int i=1; i<=height; i++){
        for (int n=i; n<height; n++){
            printf(" ");
        }
        for (int n=1; n<=i; n++){
            printf("#");
        }
        printf(" | ");
        for (int n=1; n<=i; n++){
            printf("#");
        }
        
        printf("\n");
    }
}