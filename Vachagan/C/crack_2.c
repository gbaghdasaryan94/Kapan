#include <cs50.h>
#include <stdio.h>
#include <crypt.h>
#include <string.h>

int generate(char* arr, int i, string str, int len, string hash) 
{  
    if (i == 0)
    {   
        printf("%s\n", str);
        if (!strcmp(crypt(str,"50"),hash)){
            printf("%s\n", str);
            exit(0);
        }
        return 0; 
    } 

    size_t slen = strlen(str);
    string str2 = malloc(slen++);
        
    for (int j = 0; j < len; j++) { 
        str2[0] = arr[j];
        strcat(str2, str);
        str2[slen] = '\0';
        generate(arr, i - 1, str2, len, hash); 
    }
  
    return 0; 
} 
  
int crack(char* arr, int len, string hash) 
{ 
    for (int i = 1; i <= len; i++) { 
        generate(arr, i, "\0", len, hash);
    } 
    return 0;
} 
  
int main(int argc, string argv[]) 
{ 
    if(argc != 2){  
        printf("Usage: ./crack hash\n");
        return 1;
    }
    
    const int letter_count = 52;
    string letter = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    
    string hash = argv[1];

    crack(letter, letter_count, hash); 
  
    return 1; 
} 