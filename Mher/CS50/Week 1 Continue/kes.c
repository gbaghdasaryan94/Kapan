#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <crypt.h>


int main(void)
{
    string n = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    char word[5];
    string pass = "50QHu2HtmlTQY";
    int a=strlen(n);

    for(int i=0; i<a; i++)
    {
        word[0]=n[i];
        string key = crypt(word,"50");
       
        if(strcmp(key,pass)==0)
        {
            printf("%s\n",word);
        }      
    }
    for(int i=0; i<a; i++)
    {
        word[0]=n[i];
        for(int j =0; j<a; j++)
        {
            word[1]=n[j];
            string key = crypt(word,"50");
        
            if(strcmp(key,pass)==0)
            {
                printf("%s\n",word);
            } 
        }     
    }
    for(int i=0; i<a; i++)
    {
        word[0]=n[i];
        for(int j =0; j<a; j++)
        {
            word[1]=n[j];
            for(int t=0; t<a; t++)
            {
                word[2]=n[t];
                string key = crypt(word,"50");
            
                if(strcmp(key,pass)==0)
                {
                    printf("%s\n",word);
                } 
            }
        }     
    }
    for(int i=0; i<a; i++)
    {
        word[0]=n[i];
        for(int j =0; j<a; j++)
        {
            word[1]=n[j];
            for(int t=0; t<a; t++)
            {
                word[2]=n[t];
                for(int q=0; q<a; q++)
                {
                    word[3]=n[q];
                    string key = crypt(word,"50");
                
                    if(strcmp(key,pass)==0)
                    {
                        printf("%s\n",word);
                    }
                } 
            }
        }     
    }
    for(int i=0; i<a; i++)
    {
        word[0]=n[i];
        for(int j =0; j<a; j++)
        {
            word[1]=n[j];
            for(int t=0; t<a; t++)
            {
                word[2]=n[t];
                for(int q=0; q<a; q++)
                {
                    word[3]=n[q];
                    for(int x=0; x<a; x++)
                    {
                        word[4]=n[x];
                        string key = crypt(word,"50");
                    
                        if(strcmp(key,pass)==0)
                        {
                            printf("%s\n",word);
                        }
                    }
                } 
            }
        }     
    }
}