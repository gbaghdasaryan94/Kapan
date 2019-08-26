#include <cs50.h>
#include <stdio.h>


int main(){

    long cardNum;
    int total=0;
    int bal;
    int len=0;
    long tmp;
    int n,n1,n2;
    string name="";

    do{
        cardNum=get_long("Your credit card number, please: \n");
    } while(!cardNum || cardNum<0);


    tmp=cardNum;


    while (tmp!=0){
        tmp=tmp/10;
        len++;
    }



    if( len != 16 && len!=13 && len!=15){
         printf("Your credit card is not valid aaaaa \n");
         return 1;
    }

    for (int i=0; i<len;i++){
        bal=cardNum%10;
        if(i==len-2){
            n2=bal;
        }
        if(i==len-1){
            n1=bal;
        }

        if(i%2!=0){
            bal =bal*2;
            if(bal>9){
                bal = 1 + bal%10;
            }
            total+=bal;
        } else {
            total += bal;
        }
        cardNum=cardNum/10;
    }

    n=n1*10+n2;

    if( len==15 && (n==34 || n==37) ){
       name="Amex";
    }
    else if(len==16 && n>=51 && n<=55 ){
        name="MasterCard";
    }
    else if ( (len==13 || len==16) && n1==4){
        name="Visa";
    }



    if( total%10 != 0){
        printf("Your credit card is not valid \n");
     } else {
        printf("Your credit card is  valid \nYour card name is ' %s ' \n",name);

     }


    return 0;
}