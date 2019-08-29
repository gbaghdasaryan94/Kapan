#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[]){

    if (argc != 2){
        printf("Please enter valid [KEY], ex. ./vigenere abc \n");
        return 1;
    }
    
    string keyword = argv[1];
    // printf("%s\n", argv[]);
    int keylength = strlen(keyword);
    for (int i = 0; i < keylength; i++) {
        if(tolower(keyword[i]) < 'A' || tolower(keyword[i]) > 'z' || (tolower(keyword[i]) > 'Z' && tolower(keyword[i]) < 'a')){
            printf("Please enter valid [KEY], KEY only can alpha \n");
            return 1;
        }
    }

    string sentence = get_string("plaintext : ");

    int key = 0;
    int len = strlen(sentence);

    printf("ciphertext : ");
    for (int i = 0; i < len; i++) {
        if(sentence[i] >= 'A' && sentence[i] <= 'Z'){
            sentence[i] = (char)((sentence[i] - 'A' + tolower(keyword[key++])-'a')%26 + 'A');
        }else if (sentence[i] >= 'a' && sentence[i] <= 'z'){
            sentence[i] = (char)((sentence[i] - 'a' + tolower(keyword[key++])-'a')%26 + 'a');
        }
        printf("%c",sentence[i]);
        if (key == keylength)
            key = 0;
    }
    printf("\n");  
}