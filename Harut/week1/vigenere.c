#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int shift(char c);

int main(int c, string v[])
{
    int lv=strlen(v[1]);
    char k[lv];

    for(int i=0; i<lv; i++)
    {
        if(isalpha(v[1][i]))
        {
            k[i]=v[1][i];
        }

        else printf("wrong keyword!\n");
    }

    printf("type the text\n");
    string t=get_string();
    int lt=strlen(t); char ./res[lt];

//bazhanum e xmberi
    for(int i=0; i<lt; i++)
    {
        for(int j=0; j<lv; j++)
        {
            if(i%lv==j)
            {
                res[i]=t[i]+shift(k[j]);
            }
        }
    }

printf("%s\n", res);
}

//////////functon shift lower///////////////
int shift(char c)
{
    int sh=0;
    if(isalpha(c) && islower(c))
    {
        sh=c-'a';
    }
    else

    if(isalpha(c) && isupper(c))
    {
        sh=c-'A';
    }
    return sh;
}
