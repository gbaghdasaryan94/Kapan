#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int main(int c, string v[])
{
    int k=atoi(v[1]);

    printf("write your text\n");
    string t=get_string();

    for(int i=0; i<strlen(t); i++)
    {
        if(isalpha(t[i]) && isupper(t[i]))
        {
            t[i]+=k;
            if(t[i]>'Z')
            {
                t[i]=t[i]-('Z'-'A')-1;
            }
        }

        else
        if(isalpha(t[i]) && islower(t[i]))
        {
            t[i]+=k;
            if(t[i]>'z')
            {
                t[i]=t[i]-('z'-'a')-1;
            }
        }

        printf("%c", t[i]);
    }
    printf("\n");
}
