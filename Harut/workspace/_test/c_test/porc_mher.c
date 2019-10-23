#include <string.h>
#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int angam = get_int(": ");
    char * RGB[3] = {"A","B","C"};
    int lenght = 3*angam;
    string RGB2[lenght];


    for(int x=0; x< angam; x++)
    {
        for(int i = 0; i < 3; i++)
        {
            for(int j=0; j<angam; j++)
            {
                RGB2[j]=RGB[i];
                printf("%s",RGB2[j]);
            }
        }
        printf("\n");
    }

}