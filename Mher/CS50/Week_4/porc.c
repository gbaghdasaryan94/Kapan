#include <string.h>
#include <stdio.h>
#include <cs50.h>
#include "myvariable.h"

int main(void)
{
    int length = get_int("Length: ");

    myvariable *next, *prev, *list;

    list = NULL;

    for(int i=0; i<length; i++)
    {
        next = malloc(sizeof(myvariable));
        next->a = get_int("Enter a: ");
        next->ptr = NULL;

        if(list == NULL)
        {
            list = next;
        }
        else
        {
            prev->ptr = next;
        }
        prev=next;        
    }

    int n = get_int("Test: ");

    for (myvariable *ptr = list; ptr != NULL; ptr = ptr->ptr)
    {
        if(ptr->a==n)
        {
            printf("%i\n",ptr->a);
            break;
        }
    }

}
