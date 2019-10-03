#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main (void){

string word = get_string ("Enter a enter word: ");
int x = get_int("Enter number: ");
for (int i=0; i<strlen(word); i++){
    char a = word[i];
            x= x%26;
            if (isalpha(a)){
            int newvalue = a+x;
            if ((newvalue>90 && newvalue <=96) || newvalue>122){
                newvalue = newvalue-26;
            }
            printf("%c",newvalue);
}
        if(!isalpha(a)){
            a=32;
        printf("%c",a);
}
}
}
