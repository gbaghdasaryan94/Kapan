#include <stdio.h>
#include <cs50.h>

int main()
{
    char *name = get_string("Enter name: ");
    printf("Hello, %s.", name);
}