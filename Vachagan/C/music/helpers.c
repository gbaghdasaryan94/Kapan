// Helper functions for music

#include <cs50.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    int x = fraction[0] - '0';
    int y = fraction[2] - '0';

    return x * (8 / y); 
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    char first = note[0];
    int n = strlen(note);
    char *notes = "CDEFGB";
    const int semiton[6] = {9, 7, 5, 4, 2, 2};

    double frequency  = 440.0;
    int octave = note[n-1] - '0';
     
    //  char *a = "Hello World!";
    // s="bvbrburbhlkvp";
    int i=strstr(&notes,first)-&notes;
    // char *b = strstr(notes, note[0]);

    // int i = b - a;

    // for(int i=0; i<6; i++)
    // {
    //     if(notes[i] == note[0])
    //     {
            if(note[0] == 'B')
            {
                frequency *= pow(2.0,semiton[i]/12.0);
                // continue;
            }else
            frequency /= pow(2.0,semiton[i]/12.0);
    //     }
    // }

    if (octave > 4)
        frequency *= pow(2.0, octave - 4);
    else if(octave < 4)
        frequency /= pow(2.0, 4 - octave);
    

    switch (note[1])
    {
        case 'b':
            frequency /= pow(2, 1/12.0);
            break;
        case '#':
            frequency *= pow(2, 1/12.0);
            break;
    }
    
    return round(frequency);
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    return strlen(s) == 0;
}
