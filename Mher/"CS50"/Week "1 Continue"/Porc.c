#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string n = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghiklmnopqrstuvwxy";
    string acryot = "ABFHGRJYSCMKL";

    for(int i=0,a=strlen(n); i<a; i++)
    {
        string key = crypt(n[i],"50");
        if(key == acryot)
        {
            printf("%s",n[i]);
        }
    }
}