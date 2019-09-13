#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <crypt.h>

int main(int argc,string argv[])
{
    string s = malloc(6);
    strcpy(s,"A");
    do{
        if(strcmp(argv[1],crypt(s,"50"))==0)
        {
            printf("%s\n",s);
            return 0;
        }

        s[0] = s[0] +1;

        for(int i=0;i<strlen(s);i++)
        {

        if(s[i]=='[')
        s[i] = 'a';

        if(s[i]=='{')

        {
            s[i] = 'A';
            if(s[i+1] == '\0')
            {
                s[i+1] = 'A';
            } 
            else
            {
                s[i+1] = s[i+1] +1;
            }
            
        }
        }
    }while (strlen(s) < 6);

    printf("%s\n","Not found!");
    

}