#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <math.h>

int main()
{
    string oct4[]={"C4", "C#4", "D4", "D#4", "E4", "F4", "F#4", "G4", "G#4", "A4", "A#4", "B4"};
    char o[4];
    strncpy(o, &oct4[6][1], 2);
    printf("%s\n", o);
}



