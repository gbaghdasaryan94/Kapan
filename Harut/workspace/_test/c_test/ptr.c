#include <stdio.h>
#include <cs50.h>
#include <string.h>

typedef struct student
{
    int mark;
    string name;
} tip;

int main()
{
    struct student Petros;
    for (int i=0; i<3; i++)
    {
        Petros.mark=get_int("mark=");
        Petros.name=get_string("name=");
        printf("\nmark=%i name=%s\n", Petros.mark, Petros.name);
    }
}