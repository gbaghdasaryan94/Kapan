#include <stdio.h>
#include <cs50.h>

int main()
{
    for (int i = 0; i < 10; i++)
    {
        if (i == 6)
        {
            i++;
        }
        printf("%i\n", i);
    }
}