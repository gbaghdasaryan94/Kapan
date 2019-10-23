#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <crypt.h>

int main(int c, string v[])
{
    string hash=v[1], alpha="\0ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz", salt="50";
    char key[5];
    int la=53;

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
                    string h = crypt(key, salt);
                    if(strcmp(h, hash)==0)
                    {
                        printf("%s\n", key);
                        return 0;
                    }
                }
            }
        }
    }
}
