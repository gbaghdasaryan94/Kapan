// Helper functions for music

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    int x = fraction[0] - '0';
    int y = fraction[2] - '0';
    
    return x * (8/y);
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    int n = strlen(note);
    char * base[12] = {"C4","C#4","D4","D#4","E4","F4","F#4","G4","G#4","A4","A#4","B4"};
    char * base1[12]= {"C4","Db4","D4","Eb4","E4","F4","Gb4","G4","Ab4","A4","Bb4","B4"};

    double print  = 440.0;

    char skizb[4];

    int tiv = note[n-1] - '0';

    if(n==2)
    {
        strncpy(skizb,note,2);  
    }
    else if(n==3)
    {
        strncpy(skizb,note,3);
        if(skizb[1]=='b')
        {
            for(int j=0; j<12; j++)
                base[j]=base1[j];
        }
        
    }

    skizb[n-1]='4';
     
    for(int i=0;i<12;i++)
    {
        if(strcmp(base[i],skizb)==0)
        {
            if(i<9)
            {
                float count =pow(2.0,(9-i)/12.0);
                print = round(print/count);
            }
            else if (i>9)
            {
                float count =pow(2,(i-9)/12.0);
                print = round(print*count);
            }
        }
    }
    if(tiv>4)
    {
        print *= tiv-3;
    }
    else if(tiv<4)
    {
        print /= 5-tiv;
    }
    
    return print;
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    return strlen(s)==0;
}