#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string c = get_string("enter anything: ");
    printf("Hello, %s\n", c);
}