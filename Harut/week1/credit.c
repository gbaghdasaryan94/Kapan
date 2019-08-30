#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

long long mypow();

int main(void)
{

printf("Please input Credit Card Number: ");
long c=get_long("");

int t, t2, s=0, s2=0;

    for(int i=1; i<16; i+=2)
    {
    t2=((c%mypow(10, i+1)-c%mypow(10, i))/mypow(10, i))*2;
     t=(c%mypow(10, i)-c%mypow(10, i-1))/mypow(10, i-1);

        if(t2>9)
        {
        t2=t2/10+t2%10;
        }

        s2+=t2;
        s+=t;
    }

if((s+s2)%10==0)
    {
        printf("your card is valid\n");
    }
else
    {
        printf("your card is invalid\n");
    }

}

//____________________________________________
//mypow function-y hashvum e x-i n astichan

long long mypow(int x, int n)
{

    long long number = 1;

    for (int i = 0; i < n; i++)
        number *= x;

    return(number);
}
