#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    int sum1 = 0;
    int sum2 = 0;
    string num = get_string("Please, enter your credit card number: ");
	int len = strlen(num);
    int arr[len];
	for (int i = 0; i < len; i++)
	{
		arr[i] = (int)num[i]-48;
	}
	for (int i = len-2; i>=0; i-=2){
        if(arr[i]*2<10){
            sum1=sum1+(2*arr[i]);
        } else {
            int j = 2*arr[i]/10;
            sum1 = sum1 + j +(2*arr[i]%10);
        }
    }
    for (int i = len-1; i >=0; i-=2)
    {
        sum2=sum2+arr[i];
    }
    sum2 = sum2+sum1;
    if(sum2%10 == 0) {
        printf("Your card is valid");
    } else {
        printf ("ATTENTION! Your card is INVALID!");
    }
    printf("\n");
}