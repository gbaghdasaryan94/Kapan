#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int alpha(char cc);

int main(int c, string v[])
{
    int k=atoi(v[1]);
    string t=get_string("text:");
    int lt=strlen(t);

    for(int i=0; i<lt; i++)
    {
        if(isupper(t[i]))
        {
            t[i]=(alpha(t[i])+k)%26+'A';
        }

        else
        if(islower(t[i]))
        {
            t[i]=(alpha(t[i])+k)%26+'a';
        }
    }
printf("code:%s\n", t);
}

//-----------function alpha------------

int alpha(char cc)
{
    int al=0;

    if(islower(cc))
    {
        al=cc-'a';
    }

    else

    if(isupper(cc))
    {
        al=cc-'A';
    }

    return al;
}