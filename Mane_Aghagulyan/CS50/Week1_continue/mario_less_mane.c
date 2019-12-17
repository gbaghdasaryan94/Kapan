#include <cs50.h>
#include <stdio.h>

int main(){
   int n=get_int("Height: ");
   while (n<=0 || n>93)
        {
            n=get_int("Height: ");
        }
    for (int i=0;i<n;i++){
        for (int j=0;j<n-i-1;j++)
            printf (" ");
        for (int j=n-i-1;j<n;j++)
            printf ("#");
        printf("\n");
    }
}




/*#include <stdio.h>
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

        printf("\n");
    }

}
*/