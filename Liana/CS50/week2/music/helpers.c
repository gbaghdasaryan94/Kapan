// Helper functions for music

#include <cs50.h>

#include "helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int duration(string fraction);
int frequency(string note);

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    // TODO
    int x,y;
    x = atoi(&fraction[0]);
    y = atoi(&fraction[2]);
   return 8*x/y;
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    int i, j=0;
    double hz;
    string note2=malloc(3); 
         if (strlen(note)>2)
            {
             note2[0]=note[0];
             note2[1]=note[1];    
            }
            else
            {
             note2[0]=note[0];
            }
    int oct = atoi(&note[strlen(note)-1]);
    if (oct <= 4)
       {
        oct=4-oct;   
       } 
       else 
        {oct = oct-4; }
    string sharp[]= {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};
    string bemol[]= {"C", "Db", "D", "Eb", "E", "F", "Gb", "G", "Ab", "A", "Bb", "B"};
    for (i=0; i<=12; i++)
    {
        string a = sharp[i];
        string b = bemol[i];
      if (strcmp(note2,a)==0 || strcmp(note2,b)==0) 
         {
          j= 9 - i;
          break;
         }
    }
    hz = round(pow(2.0,oct) * 440 / pow(2.0,j/12.0));
   return hz;
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    // TODO  // return strlen(s) ==0 // short version //
    if (strlen(s) ==0) 
           return true;     
    else 
        return false;   
}
