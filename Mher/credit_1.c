#include<stdio.h>

int main(void)
{
    int a=0;
    long int n = 4033190012524262;
    
    while(n>0)
    {
        a+=n%10;
        n=n/10;
    
        if(n%10*2>9)
        {
            a=a+((n%10*2)%10)+1;
            n=n/10;
        }
        else
        {
            
            a+=n%10*2;
            n=n/10;
        }
    }
    
    if(a%10==0)
        printf("your cart is correct");
    else
        printf("your cart is incorrect");
}