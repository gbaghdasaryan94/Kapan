#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>

int main(){
    long credit = get_long("Insert credit card number :");
    long CR_card = credit;
    int sum1 =0, sum2 =0, count =0, sum, tmp = 0;
    
    while (credit > 0)
    {
        credit = credit/10;
        count++;
    }
    printf("%i\n", count);
    
    while (count > 0)
        {
            tmp = CR_card % 10;
            if(tmp>4) tmp*=2;
            sum2 += tmp/10 + tmp%10;
            CR_card = CR_card/10;
            count--;
           
           sum1 += CR_card%10;
           CR_card = CR_card/10;
           count--;
    }

    sum = sum1+sum2;  

    printf("%i\n", sum1);
    printf("%i\n", sum2);
    
    printf("%i\n", sum);

    if(sum%10 == 0)   printf("%s\n", "true"); 
    else printf("%s\n", "false"); 
        
}