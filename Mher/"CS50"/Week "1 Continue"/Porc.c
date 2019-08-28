#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <crypt.h>


int main(void)
{
    string n = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghiklmnopqrstuvwxyz";
    char word[3];
    string pass = "50R.6FuTGui8U";
    int a=strlen(n);

    for(int i=0; i<a; i++)
    {
        word[0]=n[i];
        string key = crypt(word,"50");
       
        if(strcmp(key,pass)==0)
        {
            printf("%s\n",word);
        }
        
        for(int j=0; j<a; j++)
        {
            word[1]=n[j];
            string key = crypt(word,"50");   

            if(strcmp(key,pass)==0)
            {
                printf("%s\n",word);
            }

            for(int r=0; r<a; r++)
            {
                word[2]=n[r];
                string key = crypt(word,"50");

                if(strcmp(key,pass)==0)
                {
                    printf("%s\n",word);
                }
            }
        }
    }
}