#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        return 1;
    }
    //get Word...
    string word = get_string("Word: ");
    int s = strlen(word);
    char save[s];
    //get "key" word...z
    string key = argv[1];
    int v = strlen(key);
    int y = 0;

    for (int j = 0; j < s; j++)
    {
        //For short "key" word...repeat again...
        int c = (int)word[j];
        int l = (int)key[y];
        y++;
        if (y >= v)
        {
            y = 0;
        }

        // SCORE //
        if (c >= 65 && c <= 90)
        {
            if (l >= 97 && l <= 122)
            {
                c = c + l - 97;
                if (c > 90)
                {
                    c -= 26;
                }
            }
            else if (l >= 65 && l <= 90)
            {
                c = c + l - 65;
                if (c > 90)
                {
                    c -= 26;
                }
            }
        }
        else if (c >= 97 && c <= 122)
        {
            if (l >= 97 && l <= 122)
            {
                c = c + l - 97;
                if (c > 122)
                {
                    c -= 26;
                }
            }
            else if (l >= 65 && l <= 90)
            {
                c = c + l - 65;
                if (c > 122)
                {
                    c -= 26;
                }
            }
        }
        //For "Empty" space (Probel)...
        if (word[j] == ' ')
        {
            save[j] = ' ';
            y--;
        }
        else
        {
            save[j] = c;
        }
    }
    printf("%s\n", save);
}