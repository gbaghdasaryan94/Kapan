#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void) {
    
    string sentence = get_string("write a sentence > "),
    keyWord = get_string("write a lowercase keyword > ");
    
    int i, j = 0, c, l,
    n = strlen(sentence),
    m = strlen(keyWord);
    
    for( i = 0; i < n; i++) {
            l = (int)keyWord[j];
            if( (int)sentence[i] >= 65 && (int)sentence[i] <= 90 ){
                c = (int)sentence[i] + l -97;
                     j++;     
                if(c > 90) {
                    c = c -26;
                }                
            } else {
                if( (int)sentence[i] >= 97 && (int)sentence[i] <= 122) {
                    c = (int)sentence[i] + l - 97;
                     j++;
                      if(c > 122) {
                    c = c -26;
                }  
                } else {   
                    c = (int)sentence[i];
                }
            }
            if( j == m) {    
                j = 0;
            } 
           sentence[i] = (char)c;
    }
      printf("%s\n",sentence);
}