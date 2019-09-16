#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cs50.h>

typedef struct newlist
{
    char * word;
    struct newlist *ptr; 
}
newnode;

void append(newnode** list, char * data){
    newnode* node = malloc(sizeof(newnode));

    newnode* prev = *list;

    node->word = data;

    node->ptr = NULL;

    if(*list == NULL){
        *list = node;
        return;
    }
    while (prev->ptr != NULL)
        prev = prev->ptr;

    prev->ptr = node;
    return;    
}

void printList(newnode * list){

    while (list != NULL)  
    {  
        printf("%s \t",list->word);
        list = list->ptr;  
    }  
    printf("\n");
}
