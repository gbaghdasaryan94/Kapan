#include <stdio.h>
int main()
{
    float cash;
    printf("Change Owned  : ");
    scanf("%f", &cash); 
    double fraction = cash - ((long)cash);
    printf("%f",fraction);
    printf("\n");

int count25 = ((int)(fraction/0.25));
fraction = fraction - count25*0.25;

int count10 = ((int)(fraction/0.10));
fraction = fraction - count10*0.10;

int count5 = ((int)(fraction/0.05));
fraction = fraction - count5*0.05;

int count1 = ((int)(fraction/0.010));

//int count = count25 + count10 + count5 +count1;

printf(" count25= %d \n count10 = %d \n count5 = %d \n count1 = %d \n",count25, count10, count5, count1);
return 0;
}