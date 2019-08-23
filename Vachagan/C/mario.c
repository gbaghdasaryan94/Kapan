#include <stdio.h>
#include <cs50.h>

int main(){ 

    int n;

    do{
        n = get_int("Enter num : ");
    }while (n < 0);
    
    
    for(int i = 1; i<=n; i++){  // for rows
        for(int j = 0; j<n-i; j++){   // for cols " "
            printf(" ");
        }
        for(int j = n-i-1; j<n; j++){  // for cols "#"
            printf("#");
        }
        printf("\n");
    }

}

