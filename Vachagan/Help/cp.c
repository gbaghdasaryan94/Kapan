#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]){

    if (argc != 3){
        printf("Usage: ./crack copy past\n");
        return 1;
    }

    FILE* copy = fopen(argv[1],"r");
    FILE* past = fopen(argv[2],"w");

    char ch;
    while ((ch = fgetc(copy)) != EOF){
        fputc(ch,past);
    }

    fclose(copy);
    fclose(past);
    
}