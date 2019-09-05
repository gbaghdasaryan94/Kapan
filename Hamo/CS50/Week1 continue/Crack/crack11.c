#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <crypt.h>

int main(int argc, string argv[]){   

    if(argc!=2){
        printf("print the key next time \n");
        return 1;
    } 

    string hash = argv[1];

    string str="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz\n";
    int len=strlen(str);

    int i, j, k, l, m;
    int b;
  

    for(i=0; i<len; i++){
       for(j=0; j<len; j++){
           for(k=0; k<len; k++){
               for(l=0; l<len;l++){
                for(m=0; m<len;m++){    
                    char crack[5]={ str[i],str[j],str[k],str[l],,str[m] };
                    if( !strcmp(crypt(crack,"50"),hash) ){             
                        printf("pass : %s \n",crack);
                        return 0;
                   }
                    else 
                   {
                        for(b=0; b <2; b++)
                            printf(" ");
                        
                        for(b=0;b<2;b++)
                           printf("\b");
                   }
                }
               }
           }
       }
   }
    

    return 0;
}