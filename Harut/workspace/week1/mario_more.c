#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n;

    do
    {
        n = get_int("Height: ");
    }

    while (n < 1 || n > 8);

    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < n - i; j++)
        {
            printf(" ");
        }

        for (int k = 0; k < i + 1; k++)
        {
            printf("#");
        }

        printf("  ");

        for (int m = 0; m <= i; m++)
        {
            printf("#");
        }

        printf("\n");
    }
}