#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

long long mypow();

int main(void)
{
    printf("Please input Credit Card Number: ");
    float f=get_float("");
    printf("%f\n", f);
}