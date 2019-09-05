#include <stdio.h>
#include <cs50.h>
int main()
{
    
    float cash = -1;
    while (cash <0)
    {
        cash = get_float("Enter cash : ");    
    }
     float fraction = cash - ((long)cash);
     fraction = fraction*100;
    
     int cash1 = ((int)fraction);
     int count = cash1/25 + (cash1%25)/10 + ((cash1%25)%10)/5 + ((cash1%25)%10)%5;
    
     printf("%d \n",count);

    return 0;    
}