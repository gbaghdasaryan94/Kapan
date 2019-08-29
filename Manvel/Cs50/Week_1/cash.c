#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int q = 0 ;
    int n = get_int ("mutq:  ");

    while (n>0)
    {
        q=q+n/100;
        n=n%100;

        q+=n/50;
        n=n%50;

        q+=n/20;
        n=n%20;

        q+=n/10;
        n=n%10;

    }
    
        printf(" Dram =%i\n",q);
}
    