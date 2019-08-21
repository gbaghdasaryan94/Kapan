#include <stdio.h>
#include <cs50.h>


void makePyramide();

void usrInp(){
    int height = get_int("Enter pyramide height: ");

    if(height < 0 || height > 23){
        printf("Pyramid height must be more thane 0, less than 23 \n");
        printf("Please enter valid pyramid height \n");
        usrInp();
    } else {
        makePyramide(height);
    }
}

void makePyramide(int n){
    for(int i=0; i<n; i++){
           for(int j=n-1; j>=0; j--){
               if( j > i ){
                   printf(".");
               } else {
                  printf("#"); 
               }
           }
           
          printf(" ");
           
          for(int j=0; j<n; j++){
              if( j > i ){
                  printf(".");
              } else {
                  printf("#"); 
              }
          }
           
           printf(" \n");
       }
}



int main(void){
    usrInp();
}