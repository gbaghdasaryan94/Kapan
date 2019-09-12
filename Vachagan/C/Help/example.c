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

void append(newnode** list, int data){
    newnode* node = malloc(sizeof(newnode));

    newnode* prev = *list;

    node->a = data;

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

int main(){

    newnode *list; 

    list = NULL;

    append(&list, 98);
    append(&list, 15);
    append(&list, 16);
    append(&list, 79);

    while (list != NULL)  
    {  
        printf("%i  %c\n",list->a,list->ch);
        list = list->ptr;  
    }  


}