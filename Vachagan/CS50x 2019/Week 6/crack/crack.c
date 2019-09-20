#include <cs50.h>
#include <stdio.h>
#include <crypt.h>
#include <string.h>

int generate(char *arr, int i, string str, int len, string hash, char *a)
{
    if (i == 0)
    {
        printf("%s\n", str);
        if (!strcmp(crypt(str, a), hash))
        {
            printf("Success / %s / crypt = %s <=> hash = %s\n", str, crypt(str, a), hash);
            exit(0);
        }
        return 0;
    }

    size_t slen = strlen(str);
    string str2 = malloc(slen++);

    for (int j = 0; j < len; j++)
    {
        str2[0] = arr[j];
        strcat(str2, str);
        str2[slen] = '\0';
        generate(arr, i - 1, str2, len, hash, a);
    }

    return 0;
}

int crack(char *arr, int len, string hash, char *a)
{
    for (int i = 1; i <= len; i++)
    {
        generate(arr, i, "\0", len, hash, a);
    }
    return 0;
}

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./crack hash\n");
        return 1;
    }

    const int letter_count = 52;
    string letter = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    string hash = argv[1];

    char a[3] = {hash[0], hash[1], '\0'};

    crack(letter, letter_count, hash, a);

    return 1;
}

// anushree:50xcIMJ0y.RXo => YES
// brian:50mjprEcqC/ts => CA
// bjbrown:50GApilQSG3E2 => UPenn
// lloyd:50n0AAUD.pL8g => lloyd
// malan:50CcfIk1QrPr6 => maybe
// maria:509nVI8B9VfuA => TF
// natmelo:50JIIyhDORqMU => nope
// rob:50JGnXUgaafgc => ROFL
// stelios:51u8F0dkeDSbY => NO
// zamyla:50cI2vYkF0YU2 => LOL
