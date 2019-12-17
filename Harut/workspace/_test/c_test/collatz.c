#include <stdio.h>
#include <cs50.h>

int collatz(int tt);
int main()

{
    int t=get_int("tiv:");
    int c=collatz(t);
    printf("%i\n", c);
}

//_____collatz______

int collatz(int tt)
{
    if (tt==1)
    return 0;

    else if ((tt%2)==0)
    return 1+collatz(tt/2);

    else
    return 1+collatz(3*tt+1);
}