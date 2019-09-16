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

newnode *list;

void append(char * data){
    newnode* node = malloc(sizeof(newnode));

    newnode* prev = list;

    node->word = data;

    node->ptr = NULL;

    if(list == NULL){
        list = node;
        return;
    }
    while (prev->ptr != NULL)
        prev = prev->ptr;

    prev->ptr = node;
    return;    
}

void printList(newnode l){

    while (l != NULL)  
    {  
        printf("%s \t",l.word);
        l = l.ptr;  
    }  
    printf("\n");
}

int hash(string key, int size){
    int sum = 0;
    for (int i = 0; key[i] != '\0'; i++)
    {
        sum += key[i];
    }
    return sum % size;
}


int main(){

    int size  = get_int("Enter HASH table size : ");

    list = (newnode *) malloc(size * sizeof(newnode *));
    // newnode* list[size];
    
    char * value;

    int key;

    value = get_string("Enter value : ");
    key = hash(value, size);
    append(value);
    printList(list[key]);

    
    // do{   
    //     value = get_string("Enter value : ");
    //     if (!strcmp(value, "0"))
    //         break;

    //     key = hash(value, size);
    //     append(&list[key], value);
    // }
    // while (true);


    
    // for (int i = 0; i < size; i++)  
    // { 
    //     printf("%i  ",i);
    //     printList(list[i]);
    // }
    

    printf("Value : %s =>  key : %i \n", value, key);

}