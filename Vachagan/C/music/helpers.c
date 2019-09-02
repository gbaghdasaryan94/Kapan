// Helper functions for music

#include <cs50.h>
#include <string.h>
#include <math.h>

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
    int n = strlen(note);
    char * base[7] = {"C4", "D4","E4","F4", "G4", "B4"};
    int * b[7] = {9, 7, 5, 4, 2, 2};
    // char * base[12] = {"C4","C#4","D4","D#4","E4","F4","F#4","G4","G#4","A4","A#4","B4"};
    // char * base1[12]= {"C4","Db4","D4","Eb4","E4","F4","Gb4","G4","Ab4","A4","Bb4","B4"};

    double print  = 440.0;
    int tiv = note[n-1] - '0';
     
    for(int i=0;i<7;i++)
    {
        if(!strcmp(base[i],note[0]))
        {
            if(i<5)
            {
                print /= pow(2.0,(9-i)/12.0);
            }
            else if ()
            {
                print *= pow(2.0,(9-i)/12.0);
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
    // char alpha = note[0];
    // int octave = note[strlen(note) - 1] - '0';
    // char accidental = note[1];

    // double frequency = 440.0;

    // switch (alpha)
    // {
    //     case 'C':
    //         frequency /= pow(2.0, 9.0/12.0);
    //         break;
        
    //     case 'D':
    //         frequency /= pow(2.0, 7.0/12.0);
    //         break;
        
    //     case 'E':
    //         frequency /= pow(2.0, 5.0/12.0);
    //         break;
        
    //     case 'F':
    //         frequency /= pow(2.0, 4.0/12.0);
    //         break;
        
    //     case 'G':
    //         frequency /= pow(2.0, 2.0/12.0);
    //         break;
        
    //     case 'A':
    //         break;
        
    //     case 'B':
    //         frequency *= pow(2.0, 2.0/12.0);
    //         break;
    // }

    // if (octave > 4)
    //     frequency *= pow(2.0, octave - 4);
    // else if(octave < 4)
    //     frequency /= pow(2.0, 4 - octave);
    

    // switch (accidental)
    // {
    //     case 'b':
    //         frequency /= pow(2.0, 1.0/12.0);
    //         break;
    //     case '#':
    //         frequency *= pow(2.0, 1.0/12.0);
    //         break;
    // }
    
    // return round(frequency);
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    return strlen(s) == 0;
}
