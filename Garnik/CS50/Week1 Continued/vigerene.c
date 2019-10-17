#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
if (argc != 2)
{
    printf ("Usage: ./vigenere keyword\n");
    return 1;
}

 string key = argv[1];
for(int i = 0; i < strlen(key); i++)
{

    if (!isalpha(key[i]))
    {
        printf("Usage: ./vigenere keyword must be an alpha\n");
        return 1;
    }
}


    string plaintext = get_string("Pleas enter a Plaintext: ");

    printf("ciphertext: ");
    int j = 0; //to get each element of a key
 for (int i=0; i<strlen(plaintext); i++)
 {
    if (j==strlen(key)){
        j=0;
    }
    key[j]=tolower(key[j]);
    if(isalpha(plaintext[i]))
    {
        if (plaintext[i] >= 65 && plaintext[i] <= 90)
        {
            plaintext[i] = (plaintext[i]+(key[j]-97));
            if (plaintext[i] > 90)
            {
                plaintext[i] = (plaintext[i] - 26);
            }
        }
        else if (plaintext[i] >= 97 && plaintext[i] <= 122)
        {
            if (plaintext[i] +(key[j]-97) > 122)
            {
               plaintext[i] = (plaintext[i] - 26);
            }
            plaintext[i] = (plaintext[i]+(key[j]-97));
        }
        j++;
    }
     printf("%c", plaintext[i]);
}
}


