//print 2 triangles like in Mario

//print 2 triangles like in Mario

#include <stdio.h>
#include <cs50.h>

int main(void)

{

printf("enter the height of the pyramid: ");
int ee=get_int("");

    for(int e=0; e<ee; e++)
    {
        for(int s=0; s<ee-e; s++)
        {
            printf(" ");
        }

        for(int h=0; h<e+1; h++)
        {
            printf("#");
        }

        printf("\t");

        for(int h1=0; h1<=e; h1++)
        {
            printf("#");
        }
        printf("\n");
    }
}

