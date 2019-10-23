#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <crypt.h>


int main(void)
{
    string n = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghiklmnopqrstuvwxy";
    char word[5];
    for(int i=0,a=strlen(n); i<a; i++)
    {
        word[0] = n[i];
        string key = crypt(word,"50");

        printf("%s\n",key);
    }
}

