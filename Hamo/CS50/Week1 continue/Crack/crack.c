#include <cs50.h>
#include <stdio.h>
#include <crypt.h>
#include <string.h>



int main (int argc, string argv[]){


    argv[1]="50W9/ghfUb5j.";

        // if(argc!=2){
//     printf("Usage: ./crack hash \n");
//     return 1;
// }

    char salt[2];
    string str=malloc(6);
    int n;

    string hash=argv[1];

    memcpy(salt,hash,2);
    strcpy(str,"A");

    while(strlen(str)<6) {

        if ( !strcmp( hash, crypt(str,salt)) ){
            printf("pass : %s \n",str);
            return 0;
        }
        else {
            str[0]++;
            n=strlen(str);
            for(int i = 0; i < n; i++) {
                if (str[i] > 'Z' && str[i] < 'a' ) str[i]= 'a';

                if (str[i] > 'z') {
                    str[i] = 'A';
                    if(str[i + 1] == '\0' ) str[i+1] = 'A';
                        else str[i+1]++;
                }
            }
        }
    }

    free(str);

}



