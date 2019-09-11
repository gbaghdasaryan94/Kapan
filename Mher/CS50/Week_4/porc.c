#include <string.h>
#include <stdio.h>
#include <cs50.h>
#include "myvariable.h"

int main(void)
{
    int length = get_int("Length: ");
    myvariable n[length];

    for(int i=0; i<length; i++)
    {
        n[i].name = get_string("Name: ");
        n[i].room = get_int("Room: ");
    }

    for(int i=0; i<length; i++)
    {
        printf("%s is in %i.\n",n[i].name,n[i].room);
    }

    FILE *file = fopen("Student.txt","w");
    for(int i=0; i<length; i++)
    {
        fprintf(file,"%s,%i\n",n[i].name, n[i].room);
    }
    fclose(file);
}
