#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>


int main(int argc, string argv[])
{
    int lenPlain, lenKey, h=0;
    string plaintext,key;
    key = argv[1];
    lenKey=strlen(key);
    printf("Key: %s %i \n", key, lenKey);
    plaintext = get_string("Enter text: ");
    lenPlain=strlen(plaintext);
    for(int i=0; i<lenPlain; i++)
    {
        char c = plaintext[i];
        int a=0, k=0;
        if(isalpha(c))
        {
            char cc=key[h%lenKey];
            if(islower(c))
            {
                a=97;
            }
            else
            {
                a=65;
            }
            if(islower(cc))
            {
                k=97;
            }
            else
            {
                k=65;
            }
            c= a + (c - a + cc - k) % 26;
            h=h+1;
        }
        printf("%c",c);
    }
    printf("\n");
}
