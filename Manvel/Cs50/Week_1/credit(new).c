#include <stdio.h>
#include <cs50.h>

int main(void)
{
long int n = get_long ("mutq: ");
int count = 0;

while(n>0)
{
    count+=n%10;
    n=n/10;

if  (n%10*2>9)
{
    count+=(n%10*2)%10+1;
    n=n/10;
}
    else
{
    count+=n%10*2;
    n=n/10;
}
}
    if(count%10==0)

    printf("vaver\n");

    else

    printf("anvaver\n");

}