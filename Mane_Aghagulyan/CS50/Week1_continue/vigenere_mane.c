#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int shift(char c);
char cipchar(char c, int k);

int main(int argc, char *argv[])
{
    if (argc == 1 || argc > 2)
    {
        printf("Usage: ./vigenere keyword\n");
        return 1;
    }
    string text, code_text;
    int j;
    text = get_string("plaintext: ");
    code_text = text;
    string key = argv[1];
    int len_key = strlen(key);
    for (j = 0; j < len_key; j++)
    {
        if (!isalpha(key[j]))
        {
            printf("Usage: ./vigenere keyword\n");
            return 1;
        }
    }

    int len = strlen(text);
    int jj = 0;
    for (j = 0; j < len; j++)
    {
        if (isalpha(text[j]))
        {
            char c_key = key[jj % len_key];
            int j_key = shift(c_key);
            code_text[j] = cipchar(text[j], j_key);
            jj++;
        }
        else
        {
            code_text[j] = text[j];
        }
    }

    printf("ciphertext: %s\n", code_text);
    return 0;
}

int shift(char c)
{
    int j_key = ((int)c > 96) ? (int)c - 97 : (int)c - 65;
    return j_key;
}

char cipchar(char c, int k)
{
    if (islower(c))
    {
        c = (char)((((int)c - 97 + k) % 26) + 97);
    }
    else
    {
        c = (char)((((int)c - 65 + k) % 26) + 65);
    }
    return c;
}