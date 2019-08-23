#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    //get Word...
    string word = get_string("Word: ");
    int s = strlen(word);

    //get key word...
    string key = get_string("Key Word: ");
    int v = strlen(key);

    for(int j=0; j<s; j++)
    {
        int c = (int)word[j];

        if(v<s)
        {
        int l = (int)key[j];
        }

        if(c>=65 && c<=90)
        {
            if(l>=97 && l<=122)
                {
                    c=c+l-97;
                }
            else if(l>=65 && l<=90)
                {
                    c=c+l-65;
                }
        }
        else if(c>=97 && c<=122)
        {
            if(l>=97 && l<=122)
                {
                    c=c+l-97;
                }
            else if(l>=65 && l<=90)
                {
                    c=c+l-65;
                }
        }
        if(word[j] ==' ')
        {
        printf(" ");
        }
        else
        {
        printf("%c",c);
        }
    }
    printf("\n");
}
