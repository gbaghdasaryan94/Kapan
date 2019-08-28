#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <crypt.h>

int main(int c, string v[])
{
    string hash=v[1], alpha="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz", salt="50";
    char key[5];
    int la=strlen(alpha);

//______________2 cycle_________________

    for (int m=0; m<la; m++)
            {
                key[0]=alpha[m];

                for (int n=0; n<la; n++)
                {
                    key[1]=alpha[n];

                    if(strcmp(hash, crypt(key, salt))==0)
                    {
                        printf("%s\n", key);
                        break;
                    }
                }
            }

//_____________3 cycle______________

    for (int j=0; j<la; j++)
        {
            key[0]=alpha[j];

            for (int m=0; m<la; m++)
            {
                key[1]=alpha[m];

                for (int n=0; n<la; n++)
                {
                    key[2]=alpha[n];

                    if(strcmp(hash, crypt(key, salt))==0)
                    {
                        printf("%s\n", key);
                        break;
                    }
                }
            }
        }

//______________________4 cycle__________________________

    for (int i=0; i<la; i++)
    {
        key[0]=alpha[i];

        for (int j=0; j<la; j++)
        {
            key[1]=alpha[j];

            for (int m=0; m<la; m++)
            {
                key[2]=alpha[m];

                for (int n=0; n<la; n++)
                {
                    key[3]=alpha[n];

                    if(strcmp(hash, crypt(key, salt))==0)
                    {
                        printf("%s\n", key);
                        break;
                    }
                }
            }
        }
    }
}
