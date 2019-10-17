#include <cs50.h>
#include <stdio.h>

int main()
{
    int a = 0;
    do
    {
        a = get_int("Height: ");
    }
    while (a < 1 || a > 8);
    
    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= a; j++)
        {
            if (j < a - i + 1) 
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        printf("\n");
    }
    
    return 0;
}