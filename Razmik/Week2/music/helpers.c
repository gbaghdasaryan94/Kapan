// Helper functions for music

#include <cs50.h>
#include <string.h>
#include <math.h>
#include <stdio.h>

#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
   return 8/atoi(&fraction[2])*atoi(&fraction[0]);
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    string notes[] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};
    string nnote = malloc(3);
    int nnumb=9;
    int octav;
    if (strlen(note) > 2)
    {
        nnote[0]=note[0];
        nnote[1]=note[1];
        string b = malloc(2);
        b[0] = note[2];
        octav = atoi(b);
    }
    else
    {
        nnote[0]=note[0];
        string b = malloc(2);
        b[0] = note[1];
        octav = atoi(b);
    }
    for (int i=0; i < 12; i++)
    {
        if (strcmp(notes[i],nnote)==0)
            {
                nnumb=i;
                break;
            }
    }
    nnumb = 9-nnumb;
    int n = 12*(octav-4)-nnumb;   
    return pow(2,n/12.0)*440;
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    return (strlen(s)==0);
    
}
