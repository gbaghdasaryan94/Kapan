#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(int argc, string argv[]) {
    
    if(argc < 3)
        return 0;
    
    int key = atoi(argv[1]);
    string word = argv[2];
    int c;
    
    key = key % 26;
    
    for(int i = 0; i < strlen(word); i++) {
       if(( (int)word[i] >= 65 && (int)word[i] <= 90 ) || ( (int)word[i] >= 97 && (int)word[i] <= 122) ){
        c = (int)word[i] + key;
        
       if(( (int)word[i] <= 90 && c > 90 ) || ( (int)word[i] >= 97 && c > 122) ) {
            
               c = c - 26;
       }
       
        word[i] = (char)c;
    }}
    
    printf("%s\n", word); 
}
