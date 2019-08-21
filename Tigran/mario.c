#include <stdio.h>
int main()
{
    int height;
    printf("Enter a height: ");
    scanf("%d", &height); 
    while(height>23)
    { 
        if(height>23) printf("Please enter the height less than 23\n");
        scanf("%d", &height); 
    }
        for(int i=1; i <height; i++)
        {
            for(int j =0; j< height-i; j++)
            printf(" ");

            for(int k =0; k<i;k++)
            printf("#");
            
            printf(" ");

            for(int k =0; k<i;k++)
            printf("#");

            printf("\n");
        }


    return 0;
}