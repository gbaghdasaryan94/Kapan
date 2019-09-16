// Helper functions for music
#include <cs50.h>
#include <math.h>
#include "helpers.h"
#include <string.h>
#include <stdio.h>

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    if(strlen(fraction) == 1)
       return 8;
    string n = malloc(2);
    string m = malloc(2);
    n[0] = fraction[0];
    m[0] = fraction[2];
    int a = atoi(n);
    int b = atoi(m);
    int c = a*8/b;
    return  c;
}
// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    int g = 1;
    int h;
    int j=0;
    double k = 440.0;
    char l[3];
    
    string e[13] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B" };
    string f[13] = {"C", "Db", "D", "Eb", "E", "F", "Gb", "G", "Ab", "A", "Bb", "B" };

    if (strlen(note)<3){

        strncpy(l,note,1);
        string o = malloc(2);
        o[0] = note[1];
        h = atoi(o);

        if(h>4){

            g = pow(2,(h-4));

        }
        else
        {
            if(h<4)

            g = g/pow(2,(4-h));
        }
        
        for(int i = 0;i<13;i++)
        {
            string x = e[i];
            string y = f[i];
            if((strcmp(l,x)==0) || (strcmp(l,y)==0))
            {

                j = i;
                break;

            }


        }

        if(j>9)
       { j=j-9;
        k = round((g*k)*(pow(2.0,j/12.0)));
        }
        else

        if(j<9)
        {
            j = 9-j;
            k = round((g*k)/(pow(2.0,j/12.0)));

        }
        return k;

    }
    else 

        {
            string o = malloc(2);
            o[0] = note[2];
            h = atoi(o);
            strncpy(l,note,2);
            if(h>4){

            g = pow(2,(h-4));

        }
        else
        {
            if(h<4)

            g = g/pow(2,(4-h));
        }

        for(int i = 0;i<13;i++)
        {
            string x = e[i];

            if(strcmp(l,x)==0){

                j = i;
                break;

            }


        }

        if(j>9)
       { j=j-9;
        k = round((g*k)*(pow(2.0,j/12.0)));
        }
        else

        if(j<9)
        {
            j = 9-j;
            k = round((g*k)/(pow(2.0,j/12.0)));

        }
        return k;


        }


}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    return (strlen(s) == 0);
}     
