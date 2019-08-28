#include<cs50.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<crypt.h>

int main( int argc, string argv[]) 
{
    if (argc!=2) 
    {
        printf("Error!\n");
        return 1;
    }
   
    string hash;
    int j1,j2,j3,j4;
    hash=argv[1];
    string abc="\0abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int len=53;
    for (j1=0;j1<len; j1++)
    {
        for (j2=0;j2<len; j2++)  
        {
        
            for (j3=0;j3<len; j3++)  
            {
                for (j4=0;j4<len; j4++)  
                {
                    char crack[5]={abc[j4], abc[j3], abc[j2], abc[j1]};
                    
                    if(!strcmp(crypt(crack,"50"),hash))
                    {
                        printf("%s \n",crack);
                        return 0;
                    }
                }
            }
        }
        
    }   
      
}
