#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <crypt.h>


int main(void)
{
    string n = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghiklmnopqrstuvwxyz";
    char word[5];
    string pass = "50cNRQBJJ3FXI";

    for(int i=0,a=strlen(n); i<a; i++)
    {
        word[0]=n[i];
        string key = crypt(word,"50");
       
        if(strcmp(key,pass)==0)
        {
            printf("%c\n",word[0]);
        }
        
        for(int j=0; j<a; j++)
        {
            word[1]=n[j];
            string key = crypt(word,"50");   

            if(strcmp(key,pass)==0)
            {
                printf("%c\n",word[0]);
            }

            for(int r=0; r<a; r++)
            {
                word[2]=n[r];
                string key = crypt(word,"50");

                if(strcmp(key,pass)==0)
                {
                    printf("%c\n",word[0]);
                }
            }
        }
    }
}