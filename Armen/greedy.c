#include <stdio.h>
#include <cs50.h>
//coins is 1, 5, 10, 25, 50
// money is less then 1 $
int main(void){
    int money=get_int("input money: ");
    int coins=0;
    while(money>0){
        if (money>=50){
            money= money - 50;
            coins++;
        }
        else if (money >= 25) {
            money = money - 25;
            coins++;
        }
        else if (money >= 10) {
            money = money - 10;
            coins++;
        }
        else if (money >= 5) {
            money = money - 5;
            coins++;
        }
        else if (money<5) {
            coins=coins + money;
            money=0;
        }
    }
    printf("My coins count is %i \n", coins);
}