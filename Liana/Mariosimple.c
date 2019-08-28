#include  <stdio.h>
#include <cs50.h>


int main(void)

{
    int i;
    int n = get_int("n: ");
    for ( i=0; i <=n; i++ )
    {
        printf("#");
    }
    printf ("\n");
}
