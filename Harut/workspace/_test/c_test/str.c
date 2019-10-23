#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <math.h>
#include <stdlib.h>

int main()

{
    string oct4[]={"C4", "C#4", "D4", "D#4", "E4", "F4", "F#4", "G4", "G#4", "A4", "A#4", "B4"};
    char c[2];

    for(int i=0; i<12; i++)
    {
        strncpy(c, &oct4[i][0], 1);
        printf("%s\n", c);
    }
}