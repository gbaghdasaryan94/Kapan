#include <stdio.h>
#include <cs50.h>

int main(){
    int n;
    do
        {
            n=get_int("Height: ");
        } while (n<=0 || n>9);
    
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++)
        if(j<(n-i-1))
            printf (" ");
        else
            printf ("#");
        printf("  ");
        for (int j=0;j<i+1;j++)
        printf ("#");
        printf("\n");
    }

}