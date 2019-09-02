#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <crypt.h>

int main(int argc, string argv[])
{
    if (argc!=2)
    {
        printf("Please enter a valid key!     Example: ./[program name] [key]\n");
        return 1;
    }
    string argo = crypt("aba","50");//argv[1]
    int max = 1+5;//get_int("Set password max length:");
    string pass = malloc(max);
    pass[0]='A';
    do
    {
        if (strcmp(crypt(pass,"50"),argv[1])==0)
        {
            printf("%s\n",pass);
            return 0;
        }
        pass[0]=pass[0]+1;
        for (int i=0; i < strlen(pass); i++)
        {
            if (pass[i]=='[')
            {
                pass[i]='a';
                break;
            }
            else if (pass[i]=='{')
            {
                pass[i]='A';
                if (pass[i+1]=='\0')
                {
                    pass[i+1]='A';
                    break;
                }
                else
                {
                    pass[i+1]=(char)(pass[i+1]+1);
                    continue;
                }
            }
            break;
        }
    } while (strlen(pass)<max);
    printf("Can't find matching password!\n");
}