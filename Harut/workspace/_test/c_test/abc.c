#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main()

{
    string s=get_string("enter a string: ");
    int ls=strlen(s);
    int n=get_int("enter the size: ");
    string ss=malloc(n*ls);

    for(int e=0; e<n; e++)
    {
        for(int i=0; i<ls; i++)
        {
            for(int j=0; j<n; j++)
            {
                ss[j]=s[i];
                printf("%c", ss[j]);
            }
        }
        printf("\n");
    }
}