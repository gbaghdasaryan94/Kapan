#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>
int frequency(string note);

int main(void){

    frequency("A4");
    return 0;
}

int duration(string fraction)
{   
    string a = malloc(2);
    string b = malloc(2);
    a[0] = fraction[0];
    b[0] = fraction[2];
    int first = atoi(a);
    int last = atoi(b);
    int sum = first * 8 / last;
    return sum;
}

int frequency(string note)
{   
    int n = 1, m, hz = 440, index;
    string bazas[13] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B" };
    string bazab[13] = {"C", "Db", "D", "Eb", "E", "F", "Gb", "G", "Ab", "A", "Bb", "B" };
    char tact[3];

    if(strlen(note) < 3){

        strncpy(tact,note,1);
        string a = malloc(2); 
        a[0] = note[1];
        m = atoi(a);

        if(m > 4){
            n *= (m - 4);
        }else {
            if(m < 4){
                n =(n + 1) * (4 - m);
            }
        }  

        for(int i = 0; i < 12; i++){
            string str = bazas[i];
            if(strcmp(tact,str) == 0){
                index = i;
                break;
            }
        }
        printf("%s\n",tact);
        printf("%i\n",index);
        printf("%i\n",m);
        if(index < 9){
            index = 9 - index;
            hz =round(440 / (pow(2,index)/pow(2,12)));
        } else {
            if(index > 9){
            index = index - 9;
            hz =round(440 / (pow(2,index)/pow(2,12)));}        } 
        printf("%i\n",index);
        

      
        //printf("%i\n",index);
        printf("%i\n",hz);
        hz *= n;
        //return(round(hz));   
        printf("%i\n",hz);                   


    } else {
        string a = malloc(2); 
        a[0] = note[2];
        m = atoi(a);

         if(m > 4){
            n *= (m - 4);
        }else {
            if(m < 4){
                n *= (4 - m);
            }
        }  

        strncpy(tact,note,2);
        
        for(int i = 0; i < 12; i++){
            string str = bazas[i];
            string str1 = bazab[i];
            if((strcmp(tact,str) == 0) || (strcmp(tact,str1) == 0)){
                index = i;
                break;
            }
        }

        //printf("%i\n",index);
        //printf("%s\n",tact);
        //printf("%i\n",m);
        if(index < 9){
            index = 9 - index;
            hz =round(440 / (pow(2,index)/pow(2,12)));
        } else {
            if(index > 9)
            index = index - 9;
            hz =round(440 / (pow(2,index)/pow(2,12)));
        } 

       

        hz *= n;
        //return(round(hz));   
        printf("%i\n",hz);  
                      


    }

    printf("%i\n",hz);
     return 0;  


}

bool is_rest(string s)
{
    if(strlen(s) == 0)
    return true;
    return 0;
}
