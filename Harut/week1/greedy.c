//use the fewest number of coins possible to make the change

#include <stdio.h>
#include <cs50.h>

int main()

{
    printf("enter the money in cents : ");
    int м=get_int("");
    int c=м/25+м%25/10+м%25%10/5+м%25%10%5/1;
    printf("%i\n", c);
}
