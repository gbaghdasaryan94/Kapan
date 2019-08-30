#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <crypt.h>


int main(void)
{
    //test base...
    string n = "\0ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    string pass = get_string("Encrypted phrase: ");
    int a=53;

    for(int i=0; i<a; i++)
    {
        for(int j =0; j<a; j++)
        {
            for(int t=0; t<a; t++)
            {
                for(int q=0; q<a; q++)
                {
                    //encrypt elements of test base...
                    char word[5] = {n[q],n[t],n[j],n[i]};
                    string key = crypt(word,"50");
                    printf("%s\n",word);

                    //compare with input ...
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