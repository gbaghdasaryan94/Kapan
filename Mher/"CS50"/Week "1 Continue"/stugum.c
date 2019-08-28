#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <crypt.h>

int main(void)
{
    string a = crypt("ZyxA","50");
    printf("%s\n",a);
}