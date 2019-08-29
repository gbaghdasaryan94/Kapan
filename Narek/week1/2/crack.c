#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <crypt.h>

const char * eos="\0";
string inputStr;
char salt[3];
bool checkPaswd(char passwd[], int pos, char c);

int main(int argc, string argv[])
{
    if(argc < 2)
    {
        return 0;
    }
    inputStr=argv[1];
    int len = strlen(argv[1]);
    if(len==0)
    {
        return 1;
    }
    if(len >0 && len<5)
    {
        string hashedPassword = crypt(inputStr, "aa\0");
        printf("Hashed Password: %s \n", hashedPassword);
    }
    else
    {
        salt[0] = inputStr[0];
        salt[1] = inputStr[1];
        salt[2] = '\0';
        printf("Salt: %s\n", salt);
        char passwd[6];
        for(int i=0;i<6;i++)
        {
            passwd[i] = '\0';
        }
        for(int i0=65; i0<130; i0++)
        {
            if(checkPaswd(passwd, 0, i0)){
                return 0;
            }
            for(int i1=65; i1<130; i1++)
            {
                if(checkPaswd(passwd, 1, i1))
                {
                    return 0;
                }
                for(int i2=65; i2<130; i2++)
                {
                    if(checkPaswd(passwd, 2, i2))
                    {
                        return 0;
                    }
                    for(int i3=65; i3<130; i3++)
                    {
                        if(checkPaswd(passwd, 3, i3))
                        {
                            return 0;
                        }
                        for(int i4=65; i4<130; i4++)
                        {
                            if(checkPaswd(passwd, 4, i4))
                            {
                                return 0;
                            }

                        }
                    }
                }
            }
        }
        printf("Password can not be cracked\n");
    }
}

bool checkPaswd(char passwd[], int pos, char c)
{
    passwd[pos] = c;
    passwd[pos + 1] = '\0';
    string encrypted=crypt(passwd, salt);
    encrypted = strcat(encrypted, eos);
    if(strcmp(inputStr, encrypted)==0)
    {
        printf("Passwd: %s\n", passwd);
        return true;
    }
    else
    {
        return false;
    }
}
