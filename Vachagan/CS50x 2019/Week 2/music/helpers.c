// Helper functions for music

#include <cs50.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    int x = atoi(&fraction[0]);
    int y = atoi(&fraction[2]);

    return x * (8 / y);
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    char *notes = "ABCDEFG";
    int semiton[7] = {0, 2, 9, 7, 5, 4, 2};
    double frequency = 440.0;
    int octave = atoi(&note[strlen(note) - 1]);

    char *idx = strchr(notes, note[0]);
    if (idx != NULL)
    {
        int i = (int)(idx - notes);
        if (note[0] == 'B')
        {
            frequency *= pow(2.0, semiton[i] / 12.0);
        }
        else
        {
            frequency /= pow(2.0, semiton[i] / 12.0);
        }
    }

    if (octave > 4)
    {
        frequency *= pow(2.0, octave - 4);
    }

    else if (octave < 4)
    {
        frequency /= pow(2.0, 4 - octave);
    }

    switch (note[1])
    {
        case 'b':
            frequency /= pow(2, 1 / 12.0);
            break;
        case '#':
            frequency *= pow(2, 1 / 12.0);
            break;
    }

    return round(frequency);
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    return strlen(s) == 0;
}