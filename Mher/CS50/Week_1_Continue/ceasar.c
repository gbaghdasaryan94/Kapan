#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        return 1;
    }
    //The key shouldn't be more than 26...
    int key = atoi(argv[1]);
    if (key > 26)
    {
        key = key % 26;
    }
    string n = get_string("Word: ");
    int s = strlen(n);

    for (int i = 0; i < s; i++)
    {
        /*Decide which space the character belongs to.
          For capital letters ( 65-90)
          For small letters (97-122)*/
        int c = (int)n[i];
        if (c >= 65 && c <= 90)
        {
            c += key;
            if (c > 90)
            {
                c -= 26;
            }
        }
        else if (c >= 97 && c <= 122)
        {
            c += key;
            if (c > 122)
            {
                c -= 26;
            }
        }

        //For "Empty space" (Probels)...
        if (n[i] == ' ')
        {
            printf(" ");
        }
        else
        {
            n[i] = (char)c;
        }
    }
    printf("ciphertext: %s\n", n);
}
