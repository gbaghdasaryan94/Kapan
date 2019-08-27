#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>


string vigenere (string str, string key);
int keyNum (string key);
int j;


int main(int argc, string argv[]){

    if(argc!=2){
        printf("print the key next time \n");
        return 1;
    } 
    
        string key = argv[1];
        
        for(int i=0; i<strlen(key); i++){
            if( !isalpha(key[i]) ){
                printf("print the character is an alphabet next time \n");
                return 1;
            }
        }

        //char text[100];
        //printf("print the text : ");
        //scanf("%[^\n]%*c", text);
        
        string text=get_string("print the text : ");
        
        printf("%s\n",vigenere(text, key) );
        return 0;

}


string vigenere (string str, string key)
{
    int kl=strlen(key);
    string code=str ;
    int len=strlen(str);
    

    for (int i=0; i<len; i++)
    {
        int k;      
               
        if ((str[i]>96) && (str[i]<123)){
            k=keyNum(key);
            code[i]=(str[i]+k-97)%26+97;
        }
        if ((str[i]>64) && (str[i]<91)){
            k=keyNum(key);
            code[i]=(str[i]+k-65)%26+65;
        }
        else {
            code[i] = str[i];
        }
        if( j >= kl ){
            j=0;
        }
        
    }

    return code;
}


int keyNum (string key){    
    int k;
    if( (key[j]>96) && (key[j]<123) ){
            k =(key[j]-97)%26;
            j++;
    } 
    if( (key[j]>64) && (key[j]<91) ){
        k =(key[j]-65)%26;
        j++;
    }

    return k;           
}