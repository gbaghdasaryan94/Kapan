#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <crypt.h>

int main()
{
    string key="TesT", salt="50";
    string h=crypt(key, salt);
    printf("%s\n", h);
}