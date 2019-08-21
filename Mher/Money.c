#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int money = get_int("Money: ");
    int coin=0;
    while(money>0)
    {
        if(money>=50)
        {
            coin=coin + money/50;
            money=money % 50;
        }
        if(money>=25)
        {
            coin+=money/25;
            money=money % 25;
        }
        else if(money>=10)
        {
            coin+=money/10;
            money=money % 10;
        }
        else if(money>=5)
        {
            coin+=money/5;
            money=money % 5;
        }
        else if(money<=5)
        {
            coin=coin+money;
            money=0;
        }  
    }   
    printf("My coins = %i \n",coin);
}