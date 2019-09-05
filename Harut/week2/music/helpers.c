// Helper functions for music

#include <cs50.h>
#include <string.h>
#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    int dur=atoi(&fraction[0])*8/atoi(&fraction[2]);
    return dur;
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
     string oct4[]={"C4", "C#4", "D4", "D#4", "E4", "F4", "F#4", "G4", "G#4", "A4", "A#4", "B4"},
          oct4b[]={"C4", "Db4", "D4", "Eb4", "E4", "F4", "Gb4", "G4", "Ab4", "A4", "Bb4", "B4"};
    float hh;

    for(int i=0; i<12; i++)
    {
        float f=i-9;
        char noteA[2], noteV[2], oct4A[2], oct4bA[2];
        //oct4A - oct4 ic notayi 1in symbol
        //oct4bA - oct4b ic notayi 1in symbol
        //noteA - notayi 1in symbol
        //noteV - notayi verjin symbol

        strncpy(noteA, &note[0], 1);
        strncpy(oct4A, &oct4[i][0], 1);
        strncpy(oct4bA, &oct4b[i][0], 1);

        if (strcmp(note, oct4[i])==0 || strcmp(note, oct4b[i])==0)
        {
            hh=round(440*(pow(2, f/12)));
        }

        else
        if (strlen(note)==2 && strlen(oct4[i])==2 && strlen(oct4b[i])==2 && strcmp(noteA, oct4A)==0)
        {
            strncpy(noteV, &note[1], 1);
            hh=round(pow(2, (atoi(noteV)-4))*440*(pow(2, f/12)));
        }

        else
        if (strlen(note)==3 && strlen(oct4[i])==3 && strlen(oct4b[i])==3 && (strcmp(noteA, oct4A)==0 || strcmp(noteA, oct4bA)==0))
        {
            strncpy(noteV, &note[2], 1);
            hh=round(pow(2, (atoi(noteV)-4))*440*(pow(2, f/12)));
        }
    }
    return(hh);
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    return (strlen(s)==0);
}