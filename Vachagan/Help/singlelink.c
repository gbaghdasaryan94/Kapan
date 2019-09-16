#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cs50.h>

typedef struct newlist
{
    int a;
    char ch;
    struct newlist *ptr; 
}
newnode;

int main(){

    int n = get_int("Enter n : ");
    
    newnode *next, *prev, *list; 

    list = NULL;

    for (int i = 0; i < n; i++)
    {
        next = malloc(sizeof(newnode));
        next->a = get_int("Enter a : ");
        next->ch = get_char("Enter ch : ");
        next->ptr = NULL;

        if(list==NULL)
            list = next;
        else
            prev->ptr = next;
        prev = next;        
    }

    while (list != NULL)  
    {  
        printf("%i  %c\n",list->a,list->ch);
        list = list->ptr;  
    }  


}