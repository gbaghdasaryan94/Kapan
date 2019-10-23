#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <math.h>

int main()

{
    int i=9;
    float hh, f=i-9;
    char note2[2]="54";
    char p=note2[1];
    hh=round(pow(2, (atoi(p)-4)*(440*(pow(2, f/12)))));
    printf("%f\n", hh);
    printf("%c\n", p);
}