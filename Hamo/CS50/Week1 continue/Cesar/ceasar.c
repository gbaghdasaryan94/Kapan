#include <stdio.h>
#include <cs50.h>
#include <string.h>



string caesar (string str, int key);

int main(int argc, string argv[]){

    if(argc!=2){
        printf("print the key next time \n");
        return 1;
    } else {
        int key = atoi(argv[1]);
        char text[100];
        printf("print the text : ");
        scanf("%[^\n]%*c", text);
        printf("%s\n",caesar(text, key) );
        return 0;
    }

}


string caesar (string str, int key)
{
    string code=str ;
    int len=strlen(str);

    for (int i=0; i<len; i++)
    {
        if ((str[i]>96) && (str[i]<123)){
            code[i]=(str[i]+key-97)%26+97;
        }
        else if ((str[i]>64) && (str[i]<91)){
            code[i]=(str[i]+key-65)%26+65;
        }
        else {
            code[i] = str[i];
        }
    }

    return code;
}
