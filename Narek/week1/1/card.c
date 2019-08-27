//card
#include <stdio.h>
#include <cs50.h>
#include <math.h>

bool checkValidation(long card);
int getNumberAt(long number, int position);
int getNumberLength(long number);

int main(void)
{
    int sum = 0;
    long card=get_long("Card#: ");
    int length=getNumberLength(card);
    if(checkValidation(card)){
        for(int i=1; i<=length; i++){
            int n=getNumberAt(card,i);
            if(i % 2 == 0)
            {
                int s=n*2;
                if(s<10){
                    sum+=s;
                }
                else{
                    sum+= s/10 + s%10;
                }
            }
            else
            {
                sum = sum + n;
            }
        }
    }

    printf("sum: %i \n", sum);
    if(sum % 10 ==0 && sum != 0){
        printf("card is valid \n");
    }
    else{
        printf("card is invalid \n");
    }
    return 0;
}

bool checkValidation(long card){
    int i1, i2, i12, l;
    bool isValid = false;
    l=getNumberLength(card);
    if(l>12 && l<17 && card > 0){
        i1=getNumberAt(card, l);
        i2=getNumberAt(card, l-1);
        i12=10 * i1 + i2;
        if(l==15 && (i12==34 || i12==37)){
            printf("Your Card is <<AMEX>> \n");
            isValid=true;
        }
        else if(l==16 || l==13 ){
            if(i1==4){
                printf("Your Card is <<VISA>> \n");
                isValid=true;
            }
            if(l==16 && i12>=51 && i12<=55){
                printf("Your Card is <<MasterCard>> \n");
                isValid=true;
            }
        }
    }
    return isValid;
}

int getNumberAt(long number, int position)
{
    long l=number % (long)pow(10, position) / pow(10,position-1);
    return (int)l;
}

int getNumberLength(long number){
    int l=0;
    long ll = 0;
    do
    {
        l=l+1;
        ll=number / pow(10.0, l);
    }
    while(ll != 0);
    return l;
}
