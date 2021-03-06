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

    for (int i = 0; i < lt; i++)
    {
        for (int j = 0; j < lk; j++)
            {
                if (i % lk == j)
                {
                    if (isupper(t[i]))
                    {
                        t[i] = (alpha(t[i]) + alpha(k[j])) % 26 + 'A';
                    }

                    else

                        if (islower(t[i]))
                        {
                            t[i] = (alpha(t[i]) + alpha(k[j])) % 26 + 'a';
                        }
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