#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void){
    int key = get_int("Enter key : ")%26;
    string word = get_string("Enter word : ");
    
    for (int i = 0; i < strlen(word); i++) {
        if(isalpha(word[i])){
            int ascii = (word[i] < 97) ? 65 : 97;
            word[i] = (char) ((word[i] + key - ascii) % 26 + ascii);
        }
        printf("%c", word[i]);
    }

    printf("\n");

}