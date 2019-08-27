#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

char ShiftChar(char c);

int key=0;

int main(int argc, string argv[])
{
    int len;
    string plaintext;
    key = atoi(argv[1]);
    printf("Key: %i \n", key);
    plaintext = get_string("Enter text: ");
    len=strlen(plaintext);
    for(int i=0; i<len; i++)
    {
        char c=ShiftChar(plaintext[i]);
        printf("%c",c);
    }
    printf("\n");
}

char ShiftChar(char c){
    int a=0;
    if(isalpha(c)){
        if(islower(c)){
            a=97;
        }else{
            a=65;
        }
        int i = a + (c-a+key) % 26;
        return i;
    }
    else{
        return c;
    }
}
