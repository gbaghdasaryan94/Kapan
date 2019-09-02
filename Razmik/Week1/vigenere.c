#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc!=2) {
        printf("Please enter a valid key!     Example: ./[program name] [non-negative integer key]\n");
        return 1;
    }
    string key = argv[1];
    int len = strlen(key);
    for (int i=0; i < len; i++)
        key[i]=tolower(key[i])-97;
    int j = 0;
    string plain = get_string("plaintext:  ");
    int plen = strlen(plain);
    for (int i = 0; i < plen; i++)
    {
        if (isalpha(plain[i]))
        {
            int k = (int)key[j++%len];
            plain[i] = (plain[i]/32)*32+((plain[i]-(plain[i]/32)*32+k)%26);
        }
    }
    printf("ciphertext: %s\n", plain);
}