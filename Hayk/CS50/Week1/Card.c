#include <cs50.h>
#include <stdio.h>


int main(){

    long card = get_long ("Enter card number \n");

    printf("%li \n",card);
    int counter = 0;
    int mnacord = 0;
    int total = 0;

    while (card != 0)
    {
        /* code */
        mnacord = card % 10;
        card = card / 10;
        counter++;
        if (counter % 2 == 0)
        {
        mnacord = mnacord * 2;
        if (mnacord >= 10){
            mnacord = 1 + mnacord % 10;
        }
        }
        total = total + mnacord;
    }
    if (counter != 16)
    printf ("Please enter valid card number \n");
    if (total%10 == 0)
    {
        printf("Card is valid \n");
    }
    else
    {
        /* code */
        printf("Card is not valid \n");
    }
    


}
    