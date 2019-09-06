#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main (void)
{
string s = get_string ("input sentance: ");
string key = get_string ("input key: ");
int i;
int j=0;
int o;
int p;
int n = strlen(s);
int m = strlen(key);

for(i=0;i<n;i++)
{
     p = (int)key[j];

    if((int)s[i]>=65 && (int)s[i]<=90)
    {
        o=((int)s[i] + p) -97 ;
        j++; 

        if(o>90)
        {
            o-=26;
        }  
    }
    else
    {
        if((int)s[i]>=97 && (int)s[i]<=122)
        {
            o=(int)s[i] + p -97 ;
            j++;
            if(o>122)
            {
                o-=26;
            }
         }
        else
        {
            o=(int)s[i];
        }
    }

    if(j==m)

    {
        j=0;
    }
    
    s[i] = (char)o;
}
        printf("%s\n",s);

}
