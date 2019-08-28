#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void){
    int key = get_int("Enter key : ")%26;
    string word = get_string("Enter word : ");
    
    for (int i = 0; i < strlen(word); i++) {
        if((word[i] >= 'A' && word[i] <= 'Z') || (word[i] >= 'a' && word[i] <= 'z')){
            int ascii_offset = (word[i] >= 'A' && word[i] <= 'Z') ? 65 : 97;
            word[i] = (char) ((word[i] + key - ascii_offset) % 26 + ascii_offset);
        }
        printf("%c", word[i]);
    }

    printf("\n");

}