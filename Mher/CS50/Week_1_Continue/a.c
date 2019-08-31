#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int frequnce(string nota);
int duration(string nota);

int main(void)
{
    string nota = "Db4@1/2";
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
    string base[12] = {"C4","C#4","D4","D#4","E4","F4","F#4","G4","G#4","A4","A#4","B4"};

    char skizb[4];
    if(n==6)
    {
        strncpy(skizb,nota,2);  
    }
    else if(n==7)
    {
        strncpy(skizb,nota,3);
        skizb[1]='#';
    }
     
    for(int i=0;i<12;i++)
    {
        if(strcmp(base[i],skizb)==0)
        {
            if(i<9)
            {
                float count =pow(2,(9-i)/12.0);
                int print = round(440.0/count);
                printf("%i",print);
            }
            else if (i>9)
            {
                float count =pow(2,(i-9)/12.0);
                int print = round(440.0*count);
                printf("%i",print);
            }
            else if(i==9)
            {
            int print = 440;
            printf("%i",print);
            }
        }
    }
    return 0;
}