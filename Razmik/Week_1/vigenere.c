#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc!=2) {
        printf("Please enter a valid key!     Example: ./[program name] [Alphabetic key]\n");
        return 1;
    }
    for (int i=0; i < strlen(argv[1]); i++)
        if (!(isalpha(argv[1][i])))
            {
                printf("Please enter a valid key!     Example: ./[program name] [Alphabetic key]\n");
                return 1;
            }
    string plain = get_string("plaintext:  ");
    printf("ciphertext: ");
    int j = 0;
    for (int i = 0; i < strlen(plain); i++)
    {
        if (isalpha(plain[i]))
        {
            int k = tolower(argv[1][j%strlen(argv[1])])-97;
            j++;
            if (isalpha(plain[i]+k))
            {
                printf("%c",plain[i]+k);
            }
            else
            {
                printf("%c", plain[i]+k-26);
            }
        }
        else
        {
            printf("%c", plain[i]);
        }
    }
    printf("\n");
}