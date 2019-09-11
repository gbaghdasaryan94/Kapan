#include <stdio.h>
#include <cs50.h>
#include <crypt.h>
#include <string.h>

int main(void) {
    string hash = get_string("Enter your hash: ");
    int n=get_int("Enter the length of a word: ");
    string word = malloc(n);
    // abcd - 50W9/ghfUb5j.
    strcpy(word,"A");
    do {
        if (strcmp(hash,crypt(word,"50")) == 0){
            printf("%s\n", word);
            return 0;
        }
        word[0]=word[0] + 1;
        int len = strlen(word);
        for(int i = 0; i < len; i++) {
        if (word[i] == '[' ) {
            word[i]= 'a';
        }
        if (word[i] == '{') {
            word[i] = 'A';
            if(word[i + 1] == '\0' )
                word[i+1] = 'A';
            else {
                word[i+1] = word[i + 1] + 1;
            }
        }

    }
    }
    while (strlen(word) < n);
    printf("The give password does not match");
}