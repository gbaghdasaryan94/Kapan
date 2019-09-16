#include <stdio.h>
#include <cs50.h>
#include <crypt.h>
#include <string.h>

int main(int argc, string argv[])
{
    string str = malloc(6);
    // abcd - 50W9/ghfUb5j.
    strcpy(str,"A");
    do
    {
        if (strcmp(argv[1],crypt(str,"50")) == 0)
        {
            printf("%s\n", str);
            return 0;
        }
        str[0] = str[0] + 1;   
        int n = strlen(str);
        for(int i = 0; i < n; i++)
        {
        if (str[i] == '[' )
        {
            str[i] = 'a';
        }
        if (str[i] == '{')
        {
            str[i] = 'A';
            if(str[i + 1] == '\0' )
                str[i+1] = 'A';
            else
            {
                str[i+1] = str[i + 1] + 1;
            }
        }
        
    }
    } while (strlen(str) < 6);
    printf("%s\n","No muching password");
}
