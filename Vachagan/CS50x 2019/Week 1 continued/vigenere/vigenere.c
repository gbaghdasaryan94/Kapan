#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{

    if (argc != 2)
    {
        printf("Please enter valid [KEY], ex. ./vigenere abc \n");
        return 1;
    }
    
    string keyword = argv[1];
    int keylength = strlen(keyword);
    for (int i = 0; i < keylength; i++) 
    {
        if (!isalpha(keyword[i]))
        {
            printf("Please enter valid [KEY], KEY only can alpha \n");
            return 1;
        }
    }

    string sentence = get_string("plaintext: ");

    int key = 0;
    int len = strlen(sentence);
    
    printf("ciphertext: ");
    for (int i = 0; i < len; i++) 
    {
        if (isalpha(sentence[i]))
        {
            int ascii = (sentence[i] < 97) ? 65 : 97;
            sentence[i] = (char)((sentence[i] - ascii + tolower(keyword[key++]) - 'a') % 26 + ascii);
        }
        printf("%c", sentence[i]);
        if (key == keylength)
        {
            key = 0;
        }
    }
    printf("\n");  
}