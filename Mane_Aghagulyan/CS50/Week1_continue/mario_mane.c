#include <stdio.h>
#include <cs50.h>

int main(){

    int n=get_int(" Input integer number from 0 to 23 ");

    while (n<0 || n>23)
        {
            n=get_int(" Input integer number from 0 to 23 ");
        }
    for (int i=1;i<n;i++){
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