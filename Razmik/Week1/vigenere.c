#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc!=2) {
        printf("Please enter a valid key!     Example: ./[program name] [key]\n");
    return 1;
    }
    string key = argv[1];
    for (int i=0; i < strlen(key); i++)
        key[i]=tolower(key[i]);
    int j = 0;
    string plain = get_string("plaintext:  ");
    printf("ciphertext: ");
    for (int i = 0; i < strlen(plain); i++)
    {
        if (isalpha(plain[i]))
        {
            int k = (int)key[j%strlen(key)]-97;
            if (isalpha(plain[i]+k))
            {
                printf("%c",plain[i]+k);
            }
            else
            {
                printf("%c", plain[i]+k-26);
            }
            j++;
        }
        else
        {
            printf("%c", plain[i]);
        }
    }
    printf("\n");
}