#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    
    int key = atoi(argv[1]) % 26;
    string word = get_string("plaintext: ");
    printf("ciphertext: ");
    for (int i = 0; i < strlen(word); i++) 
    {
        if (isalpha(word[i]))
        {
            int ascii = (word[i] < 97) ? 65 : 97;
            word[i] = (char)((word[i] + key - ascii) % 26 + ascii);
        }
        printf("%c", word[i]);
    }

    printf("\n");
    return 0;
}