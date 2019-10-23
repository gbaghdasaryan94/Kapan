#include <stdio.h>
#include <cs50.h>

void swap(int a, int b);
int main()
{
    int x=get_int("x=");
    int y=get_int("y=");
    swap(x, y);
    printf("\nx=%i\ny=%i\n", x, y);
}

void swap(int a, int b)
{
    int c=a;
        a=b;
        b=c;
}