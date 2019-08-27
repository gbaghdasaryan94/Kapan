//credit card validation
#include <stdio.h>
#include <cs50.h>

int main() {

    
        int  i=0;
        long number,sum=0,num;
        do
            {
            number=get_long("Input valid number ");
        } while(number<1000000000);

        while(number>0)
        {
            num=number%10;
            number/=10;
            i++;
            if(i%2==0)
            {
                if (num*2>9)
                    sum=sum+(num*2)/10+(num*2)%10;
                else
                    sum=sum+(num*2);
            }
            else
                {
                    sum+=num;
                }
        }
        if(sum%10==0 && sum!=0)
            printf("Your card is valid \n");
        else
            printf("Your card is not valid \n");
        printf(" sum= %li \n",sum);
    }