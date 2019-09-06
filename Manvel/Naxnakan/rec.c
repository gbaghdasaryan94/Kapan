#include <stdio.h>
#include <cs50.h>

int r(int n);
int main(void)
{

    int x = get_int ("mutq: ");
    printf("%i\n",r(x));
    return 0;
}
int r(int n)
{
if(n>0)
{
    return  n+r(n-1);
}
    else
    {
        return 0;
    }


}