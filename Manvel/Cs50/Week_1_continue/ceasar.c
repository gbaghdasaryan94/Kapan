#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    int key=get_int ("input key: ");
    key=key%26;
    int final;
    string word=get_string ("input word: ");
    for(int i=0;i<strlen(word);i++){
        // char item=word[i];
        if(isalpha(word[i])){
            final=word[i]+key;
        }else
        {
            final=word[i];
        }
        if((final>90 && final<97) || final>122){
            final=final-26;
        }
        printf("%c",final);
    }
    printf("\n");
}


