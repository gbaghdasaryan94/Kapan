#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <crypt.h>


int main(void)
{
    string n = "\0ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    string pass = "50VxqXoSfyiuc";
    int a=53;

    for(int i=0; i<a; i++)
    {
        for(int j =0; j<a; j++)
        {
            for(int t=0; t<a; t++)
            {
                for(int q=0; q<a; q++)
                {
                    for(int x=0; x<a; x++)
                    {
                        char word[5] = {n[x],n[q],n[t],n[j],n[i]};
                        string key = crypt(word,"50");
                        printf("%s\n",word);
                    
                        if(strcmp(key,pass)==0)
                        {
                            printf("%s\n",word);
                            return 0;
                        }
                    }
                } 
            }
        }     
    }
}