#include <cs50.h>
#include <stdio.h>
#include <crypt.h>
#include <string.h>

/**
 *    1 2 3 4 5 6
 * 1) X\0\0\0\0\0
 * 2) X X\0\0\0\0
 * 3) X X X\0\0\0
 * 4) X X X X\0\0
 * 5) X X X X X\0
 */

int main(int argc, string argv[])
{

    if (argc != 2)
    {
        printf("Usage: ./crack hash\n");
        return 1;
    }

    const int letter_count = 53;
    string letter = "\0abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    string hash = argv[1];
    char a[3] = {hash[0], hash[1], '\0'};
    // char key[6] = "\0\0\0\0\0\0";

    // one two three four five
    for (int five = 0; five < letter_count; five++)
    {
        for (int four = 0; four < letter_count; four++)
        {
            for (int three = 0; three < letter_count; three++)
            {
                for (int two = 0; two < letter_count; two++)
                {
                    for (int one = 0; one < letter_count; one++)
                    {
                        char key[6] = 
                        {
                            letter[one],
                            letter[two],
                            letter[three],
                            letter[four],
                            letter[five],
                            '\0'
                        };
                        printf("%s \n", key);

                        if (!strcmp(crypt(key, a), hash))
                        {
                            printf("Success / %s / crypt = %s <=> hash = %s\n", key, crypt(key, a), hash);
                            return 0;
                        }
                    }
                }
            }
        }
    }

    return 2;
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
