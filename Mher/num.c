#include<stdio.h>

int main()
{
    int num = 789;
    int sum;
    
    do
    {
        sum = 0;
        do
        {
            sum += num % 10;
            num = num/10;
        }
        while(num>0);
        
        num = sum;
    }
    while(sum > 9);
    
    printf("sum = %i \n",sum);
}

