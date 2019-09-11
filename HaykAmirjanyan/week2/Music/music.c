#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>
int frequency(string note);
int duration(string fraction);

int main(void){

    duration("3/8");
    frequency("G5");
    //return 0;
}

int duration(string fraction)
{   if(strlen(fraction) == 1){
    printf("%i\n",8);
    return 0;
}
    string a = malloc(2);
    string b = malloc(2);
    a[0] = fraction[0];
    b[0] = fraction[2];
    int first = atoi(a);
    int last = atoi(b);
    int sum = first * 8 / last;
    printf("%i\n", sum);
    return 0;
}

int frequency(string note)
{
    int n = 1, m, index = 0;
    double  hz = 440.0;
    string bazas[13] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B" };
    string bazab[13] = {"C", "Db", "D", "Eb", "E", "F", "Gb", "G", "Ab", "A", "Bb", "B" };
    char tact[3];

    if(strlen(note) < 3){

        strncpy(tact,note,1);
        string a = malloc(2); 
        a[0] = note[1];
        m = atoi(a);

        if(m > 4) 
        {
            n = pow(2,(m - 4));
        }else {
            if(m < 4)
            {
                n = n / pow(2,(4 - m));
            }
        }  

        for(int i = 0; i < 13; i++){
            string str = bazas[i];
            if(strcmp(tact,str) == 0){
                index = i;
                break;
            }
        }

        if(index < 9){
            index = 9 - index;
            hz =round((n * hz) / (pow(2.0,index / 12.0)));
        } else {
            if(index > 9){
            index = index - 9;
            hz =round((n * hz) * (pow(2.0,index / 12.0)));}        
            }    

         printf("%f\n",hz); 
         return 0;
         //return hz;  

    } else {
        string a = malloc(2); 
        a[0] = note[2];
        m = atoi(a);

         if(m > 4 ){
            n = pow(2,(m - 4));
        }else {
            if(m < 4){
                n = n / pow(2,(4 - m));
            }
        }  

        strncpy(tact,note,2);
        
        for(int i = 0; i < 13; i++){
            string str = bazas[i];
            string str1 = bazab[i];
            if((strcmp(tact,str) == 0) || (strcmp(tact,str1) == 0)){
                index = i;
                break;
            }
        }

        if(index < 9){
            index = 9 - index;
            hz =round((n * hz) / (pow(2.0,index / 12.0)));
        } else {
            if(index > 9)
            index = index - 9;
            hz =round((n * hz) * (pow(2.0,index / 12.0)));
        } 

        printf("%f\n",hz); 
        //return hz;       
        return 0;            

    }
}

bool is_rest(string s)
{
    if(strlen(s) == 0)
    return true;
    return 0;
}
