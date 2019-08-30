#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int frequnce(string nota);

int main(void)
{
    string nota = "D4@1/2";
    frequnce(nota);
    
}



int duration(string nota)
{
    int n = strlen(nota);
    if(nota[n-1]==56 )
    {
        printf("%i\n",(int)nota[n-3]-48);
    }
    else if(nota[n-1]==52)
    {
        printf("%i\n",2);
    }
    else if(nota[n-1]==50)
    {
        printf("%i\n",4);
    }
    return 0;
}

int frequnce(string nota)
{
    int n = strlen(nota);
    string base[12] = {"C","C#","D","D#","E","F","F#","G","G#","A","A#","B"};
    if(n==6)
    {
        for(int i=0;i<12;i++)
        {
            char o[1];
            strncpy(o,nota,1);
            printf("%s",o);
            printf("%s",base[i]);
            if(base[i]==o)
            {
                printf("%s",base[i]);
            }
        }
    }




    return 0;
}


