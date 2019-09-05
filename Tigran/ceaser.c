#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main()
{

   int key = get_int("Enter key  : ");
   string plaintext = get_string("Plaintext  : ");
   char ciphertext[strlen(plaintext)];
   
   for(int i=0; i < strlen(plaintext); i++)
     {  
        if(((int)plaintext[i]>=(int)'A' && (int)plaintext[i]<=(int)'Z'))
        { 
            ciphertext[i]= 65 + (plaintext[i]+key - 97)%26;
            continue;
        }
        if(((int)plaintext[i]>=(int)'a' && (int)plaintext[i]<=(int)'z'))
        {
            ciphertext[i]= 97 + (plaintext[i]+key - 97)%26;
            continue;
        }
        else
        {
            ciphertext[i]=plaintext[i];
        }
     }
    printf("Ciphertext : ");

    for(int i=0; i < strlen(plaintext); i++)
        printf("%c", ciphertext[i]);
    
    printf("\n");
}