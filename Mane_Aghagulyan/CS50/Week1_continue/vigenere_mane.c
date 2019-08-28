#include<cs50.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main( ) 
{
    string text, code_text;
    int j;
    text=get_string("Enter a base string ");
    code_text=text;
    string key=get_string("Enter a key string ");
    int len=strlen(text);
    int len_key=strlen(key);
    int jj=0;
    for(j=0; j<len; j++)
        {
            char c=text[j];
            if( isalpha(c)) {
                    char c_key=key[jj%len_key];
                    int j_key=((int)c_key>96)?(int)c_key-97 :(int)c_key-65 ;

                    if(islower(c)) 
                    {
                        c = (char) ((((int) c - 97 + j_key) % 26) + 97);
                    }
                    else {
                    c = (char) ((((int) c-65 + j_key)%26)+65);
                }
                jj++;
            }
            code_text[j]=c;
        }        
            
    printf("Crypted text is %s \n",code_text);
}