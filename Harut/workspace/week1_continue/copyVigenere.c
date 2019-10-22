#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int alpha(char cc);

int main(int c, string v[])
{
    if (c != 2)
    {
        printf("Usage: ./vigenere keyword\n");
        return 1;
    }

    string k = v[1];
    string t = get_string("plaintext: ");
    int lt = strlen(t), lk = strlen(k);

    int j = 0;
    for (int i = 0; i < lt; i++)
    {
        if (isalpha(t[i]))
        {
            if (isupper(t[i]))
            {
                t[i] = (alpha(t[i]) + alpha(k[j])) % 26 + 'A';
            }

            else
            {
                t[i] = (alpha(t[i]) + alpha(k[j])) % 26 + 'a';
            }

            j++;

                if (k[j] == '\0')
                {
                    j = 0;
                }
        }
    }
    printf("ciphertext: %s\n", t);
}

//-----------function alpha------------

int alpha(char cc)
{
    int al = 0;

    if (islower(cc))
    {
        al = cc - 'a';
    }

    else

        if (isupper(cc))
        {
            al = cc - 'A';
        }

    return al;
}