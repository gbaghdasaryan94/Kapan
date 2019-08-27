#include <stdio.h>
#include <cs50.h>
int main()
{
    int arr[5] = {25, 10, 5, 1};
    int i,
    sum = 0;
    int money = get_int("Give me my money!!! ");
    for(i = 0; i < 4; i++) {
        sum += money / arr[i];
        money = money % arr[i];
    }
    printf("%i\n",sum);
}