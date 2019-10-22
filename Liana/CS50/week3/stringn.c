#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main ()
{

string s = get_string ("input string: ");
// string s1;
int n = get_int ("Give me a multiple");
int l=strlen(s);
// printf ("%c\n", s[1]);
for (int i=0; i<l; i++)
    {
    for(int j=0; j<=n; j++)
       {
        printf ("%c", s[j]);
       }  
    // printf ("\n");
    }
       // {

        // string s1 =s[i];   
       // }  
   // }





}