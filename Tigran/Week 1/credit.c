#include <stdio.h>
#include <cs50.h>

int main(){
    long credit = get_long("Insert credit card number :");
   
    int  sum=0, tmp = 0;

    while (credit > 0)
        {
           sum += credit%10;
           credit = credit/10;

           tmp = credit%10;
           tmp*=2;
           sum+= tmp%10 + tmp/10;
           
           credit = credit/10;
           
           
    }
    printf("%i\n", sum);

    if(sum%10 == 0)   printf("%s\n", "true"); 
    else printf("%s\n", "false"); 
        
}