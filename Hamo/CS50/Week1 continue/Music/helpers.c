// Helper functions for music

#include <cs50.h>

#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    return ( (atoi(fraction[0]))*8/(atoi(fraction[2])) );
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    float freq=440.0;
    int ln = strlen(note);

    char c=note[ln-1];    
    oct = atoi(c);    

    if(oct > 4){
        freq *=pow(2;(oct-4));
    } else {
        freq /=pow(2,(4-oct));
    }

    char frst_let=note[0];

    float k;

    switch(frst_let) {
      case 'A' :
        k=freq;
        break;
      case 'B' :
        k=freq*pow(2,2/12.0);
        break;
      case 'C' :
        k=freq*pow(2,3/12.0);
        break;
      case 'D' :
        k=freq*pow(2,5/12.0);
        break;
      case 'F' :
        k=freq*pow(2,8/12.0);
        break;
      case 'G' :
        k=freq*pow(2,10/12.0);
        break;
      default :
         printf("Invalid \n" );
   }
    if(ln>2){
        if( not[1]=='#'){
            k=k*pow(2,1/2.0);
        }
        if(not[1]=='b'){
            k=k/pow(2,2/12.0);
        }
    }

    return (int)k;
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    if(s[0]=='\0') return true;
    
}
