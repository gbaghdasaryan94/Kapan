#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <math.h>

int duration(string fraction);
int main()

{
    int dt=duration("3/4");
    printf("%i\n", dt);
}

int duration(string fraction)
{
    int dur=atoi(&fraction[0])*8/atoi(&fraction[2]);
    return dur;
}