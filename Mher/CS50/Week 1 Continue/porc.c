#include <stdio.h>
#include <cs50.h>
#include <string.h>

int lenghts(string nota);

int main(void)
{
    string nota = "D4@3/4";
    lenghts(nota);
    
}



int lenghts(string nota)
{
    int n = strlen(nota);
    if(nota[n-1]==56 )
    {
        printf("%i",(int)nota[n-3]-48);
    }
    else if(nota[n-1]==52)
    {
        printf("%s","2/8");
    }
    else if(nota[n-1]==50)
    {
        printf("%s","4/8");
    }
    return 0;
}