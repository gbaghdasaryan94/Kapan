#include <math.h>
#include <stdio.h>
#include <cs50.h>
#include <string.h>


int duration(string note);

int main(){
    string m="C4@1/4";

    duration(m);
    return 0;
}


int duration(string note){
    string result = note.Substring(0,2);
    printf("%s",result);
    return result;

}