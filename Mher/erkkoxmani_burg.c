#include <stdio.h>

int main(void)
{
    int height=5;
    
    for (int i=0; i<height; i++) 
    {
        for (int j=i; j<height; j++)
        {
            printf(" ");
        }
        
        for (int n=1; n<=i; n++)
        {
            printf("#");
        }
        for (int n=1; n<=i; n++)
        {
            printf("#");
        }
        
        printf("\n");
        
    }
}