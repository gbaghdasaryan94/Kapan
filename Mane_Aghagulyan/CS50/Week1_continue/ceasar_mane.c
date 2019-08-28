#include<cs50.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(int argc, char * argv[]) 
{
    if ( argc == 1 ) 
    {
        printf( "No arguments were passed.\n" );
        } else {
                string text, code_text;
                int j;
                text=get_string("Enter a base string ");
                code_text=text;
                int key=atoi(argv[1]) %26;
                int len=strlen(text);
                for(j=0; j<len; j++)
                    {
                        char c=text[j];
                        if( isalpha(c)) {
                            if(islower(c)) 
                            {
                                c = (char) ((((int) c - 97 + key) % 26) + 97);
                            }
                        else 
                        {
                            c = (char) ((
                                ((int) c-65 + key)%26)+65);
                            
                        } 
                        code_text[j]=c;
                    }
                
            }
        printf("Crypted text is %s \n",code_text);
    }
}