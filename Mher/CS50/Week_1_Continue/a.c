#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int frequnce(string nota);
int duration(string nota);

int main(void)
{
    string nota = "Eb3@1/2";
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
    string base1[12]= {"C4","Db4","D4","Eb4","E4","F4","Gb4","G4","Ab4","A4","Bb4","B4"};

    int angam = 1;
    int stugel = 0;
    char skizb[4];
    if(n==6)
    {
        strncpy(skizb,nota,2);  
    }
    else if(n==7)
    {
        strncpy(skizb,nota,3);
        if(skizb[1]=='b')
        {
            for(int j=0; j<12; j++)
            base[j]=base1[j];
        }

        int tiv = (int)skizb[2]-48;
        if(tiv!=4)
        {
            skizb[2]='4';
        }

        if(tiv>4)
        {
            angam=tiv-3;
            stugel = 1;
        }
        else if(tiv<4)
        {
            angam=5-tiv;
            stugel = 2;
        }
        
    }
     
    for(int i=0;i<12;i++)
    {
        if(strcmp(base[i],skizb)==0)
        {
            if(i<9)
            {
                float count =pow(2,(9-i)/12.0);
                int print = round(440.0/count);
                if(stugel==1)
                {
                    print*=angam;
                }
                else if(stugel ==2)
                {
                   print/=angam; 
                }
                printf("%i",print);
            }
            else if (i>9)
            {
                float count =pow(2,(i-9)/12.0);
                int print = round(440.0*count);
                if(stugel==1)
                {
                    print*=angam;
                }
                else if(stugel ==2)
                {
                   print/=angam; 
                }
                printf("%i",print);
            }
            else if(i==9)
            {
                int print = 440;
                if(stugel==1)
                {
                    print*=angam;
                }
                else if(stugel ==2)
                {
                    print/=angam; 
                }
                printf("%i",print);
            }
        }
    }
    return 0;
}
