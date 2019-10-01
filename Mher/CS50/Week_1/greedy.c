#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main()
{
    float money1;
    do
<<<<<<< HEAD
    {
        money1 = get_float("Money: ");
    }
    while (money1 < 0);
    
    int money = round(money1 * 100);
    printf("%i", money);
    int coin = 0;
    while (money > 0)
    {
        if (money >= 25)
        {
            coin += money / 25;
            money = money % 25;
        }
        else if (money >= 10)
        {
            coin += money / 10;
            money = money % 10;
        }
        else if (money >= 5)
        {
            coin += money / 5;
            money = money % 5;
        }
        else if (money <= 5)
        {
=======
    money1 = get_float("Money: ");
    while(money1>0);
    int money = round(money1 * 100);
    printf("%i",money);
    int coin = 0;
    while(money > 0)
    {
        if(money >= 25)
        {
            coin += money / 25;
            money = money % 25;
        }
        else if(money >= 10)
        {
            coin += money / 10;
            money = money % 10;
        }
        else if(money >= 5)
        {
            coin += money / 5;
            money = money % 5;
        }
        else if(money <= 5)
        {
>>>>>>> 95ff23b9b589ed69911f0bc746e0b79fac46ab74
            coin = coin + money;
            money = 0;
        }  
    }   
    printf("My coins = %i \n", coin);
}
