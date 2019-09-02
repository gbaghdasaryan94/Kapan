// Helper functions for music

#include <cs50.h>
#include "helpers.h"
#include<math.h>

#include <string.h>


// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    return (fraction[0]-'0')*(8/(fraction[2]-'0'));
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    double freq=440.0;
    
    // calculate octave    
    int oct=(note[strlen(note)-1]-'0');
    

    //calculate note
    switch(note[0])
    {
        case 'A': break;
        case 'B': freq=freq*pow(2.0,2.0/12.0); break;
        case 'C': freq=freq/pow(2.0,9.0/12.0); break;
        case 'D': freq=freq/pow(2.0,7.0/12.0); break;
        case 'E': freq=freq/pow(2.0,5.0/12.0); break;
        case 'F': freq=freq/pow(2.0,4.0/12.0); break;
        case 'G': freq=freq/pow(2.0,2.0/12.0); break;
    }
    if (oct>4)
        freq=freq*pow(2.0,oct-4);
    else
        freq=freq/pow(2.0,4-oct);
    
    //calculate # or b
    if(note[1]=='#')
        freq=freq*pow(2.0,1.0/12.0);
    if(note[1]=='b')
        freq=freq/pow(2.0,1.0/12.0);
    
    return round(freq); 
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    // if(strlen(s)==0)
        return strlen(s)==0;
}
