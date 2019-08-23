#include <stdio.h>
#include <cs50.h>

int get_positive_int(string prompt);

int main(void)
{
    int i = get_positive_int("positiv integer:\n");
    printf("%i\n", i);
}

int get_positive_int(string prompt)
{
    int n;
    do
    {
       n = get_int("%s",prompt);
    }
    while(n<1);
    return n;
}


