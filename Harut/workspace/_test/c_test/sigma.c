#include <stdio.h>
#include <cs50.h>

int sigma(int tt);
int main()

{
    int t=get_int("tiv:");
    int s=sigma(t);
    printf("%i\n", s);
}

//_________function sigma

int sigma(int tt)
{
    int ss=0;

    for (int i=0; i<=tt; i++)
    {
        ss+=i;
    }

    return ss;
}