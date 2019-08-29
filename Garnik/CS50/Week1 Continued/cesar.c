#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main (void){

string word = get_string ("Enter a senter word: ");
int x = get_int("Enter number: ");
for (int i=0; i<strlen(word); i++){
    char a = word[i];
            if (x>=26)
            {
                x= x%26;
            }
            if (isalpha(a)){
            int newvalue = a+x;
            if ((newvalue>90 && newvalue <=96) || newvalue>122){
                newvalue = newvalue-26;
            }


            char n1 = (char) newvalue;
            printf("%c",n1);
}
}
}
