#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void) {
    
    int key = get_int("write a key > "), i, c;
    string word = get_string("write a word > ");
    
    key = key % 26;
    
    for(i = 0; i < strlen(word); i++) {
       
        c = (int)word[i] + key;
        
       if(( (int)word[i] <= 90 && c > 90 ) || ( (int)word[i] >= 97 && c > 122) ) {
            
               c = c - 26;
       }
       
        word[i] = (char)c;
    }
    
    printf("%s\n", word); 
}