#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include <crypt.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if(argc!=2)
    {
        printf("Please enter valid crypt\n");
        return 1;
    }
    string pass="";
    pass = malloc(6);
    strcpy(pass, "A");
    do
    {
        if(strcmp(crypt(pass,"50"),argv[1])==0)
            {
                printf("%s\n",pass);
                return 0;
            }
        pass[0]=(char)((int)pass[0]+1);
        if (!isalpha(pass[0]))
            for (int i = 0; i < 5; i++)
            {
                if (pass[i]=='[')
                {
                    pass[i]='a';
                    break;
                }
                else if (pass[i]=='{')
                {
                    pass[i]='A';
                    if (!pass[i+1])
                    {
                        pass[i+1]='A';
                        break;
                    }
                    else
                        pass[i+1]=(char)((int)pass[i+1]+1);
                }
                else
                    break;
            }
    } while(strlen(pass)<6);
    printf("Can't find matching password\n");
}
