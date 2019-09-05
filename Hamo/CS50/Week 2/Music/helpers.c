// Helper functions for music
#include <math.h>
#include <cs50.h>
#include <string.h>
#include "helpers.h"


// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    int c1=fraction[0] - '0';
    int c2=fraction[2] - '0';
    return c1*(8/c2);
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    double freq=440.0;
    int ln = strlen(note);

    int oct = note[ln-1]-'0';

    if(oct > 4){
        freq *=pow(2.0,(oct-4));
    } else {
        freq /=pow(2.0,(4-oct));
    }

    char frst_let=note[0];

    // int k;

    switch(frst_let) {
      case 'A' :
        break;
      case 'B' :
        freq *= pow(2,2/12.0);
        break;
      case 'C' :
        freq/=pow(2,9/12.0);
        break;
      case 'D' :
        freq/=pow(2,7/12.0);
        break;
      case 'E' :
        freq/=pow(2,5/12.0);
        break;
      case 'F' :
        freq/=pow(2,4/12.0);
        break;
      case 'G' :
        freq/=pow(2,2/12.0);
        break;
   }
    if(ln>2){
        if( note[1]=='#'){
            freq*=pow(2,1/12.0);
        }
        if(note[1]=='b'){
            freq/=pow(2,2/12.0);
        }
    }

    return round(freq);
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    if(s[0]=='\0') return true;
    else return false;
}
