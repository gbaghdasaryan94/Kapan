#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Please enter a valid key!     Example: ./[program name] [non-negative integer key]\n");
        return 1;
    }
    int k = atoi(argv[1]) % 26;
    string plain = get_string("plaintext: ");
    for (int i = 0; i < strlen(plain); i++)
    {
        if (isalpha(plain[i]))
        {
            plain[i] = (plain[i] / 32) * 32 + ((plain[i] - (plain[i] / 32) * 32 + k) % 26);
        }
    }
    printf("ciphertext: %s\n", plain);
}