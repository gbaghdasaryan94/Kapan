#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main (void){

int j =0;
string key = get_string("Enter keyword: ");
string plaintext = get_string("Enter plaintext: ");
for (int i=0; i<strlen(plaintext); i++){
    if (j==strlen(key)){
        j=0;
    }
    key[i]=tolower(key[i]);
    if(isalpha(plaintext[i])){
    plaintext[i] = plaintext[i]+(key[j]-97);
    if (plaintext[i]>122){
        plaintext[i]= plaintext[i]-25;
    }
    j++;
}
}
printf("%s",plaintext);
    printf("\n");

}