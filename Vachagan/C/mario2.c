#include <stdio.h>
#include <cs50.h>

int main(){ 

    int n;

    do{
        n = get_int("Enter num : ");
    }while (n < 0);
    
    
    for(int i = 0; i<n; i++){  // for rows
        for(int j = 0; j<n-i-1; j++){   // for cols " "
            printf(" ");
        }
        for(int j = 0; j<=i; j++){  // for cols "#"
            printf("#");
        }
        printf(" ");
        for(int j = 0; j<=i; j++){  // for cols "#"
            printf("#");
        }
        printf("\n");
    }

}

