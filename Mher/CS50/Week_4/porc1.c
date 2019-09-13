#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include<cs50.h>


typedef struct node
{
    char *word1[10];
    struct node* next;
}
node;

int main(void)
{
    int length = get_int("Length: ");
    node hashtable[length];

    for (int i=0; i < length; i++)
    {
        hashtable[i].next = NULL;
        *hashtable[i].word1 = NULL;
    }

    string word = get_string("word: ");

    int count=0;
    for(int i=0; i< strlen(word); i++)
    {
        count+=toupper((int)word[i]);
    }
    count%=length;
    printf("%i\n",count);

    *hashtable[3].word1="aaa";

    node *next1, *prev, *list;
    list = NULL;
    prev = NULL;
    
    if(*hashtable[count].word1==NULL)
    {
        *hashtable[count].word1 = word;
    }
    else
    {

        next1 = malloc(sizeof(node));
        *next1->word1 = word;
        next1->next = NULL;

        if(list == NULL)
        {
            list = next1;
        }
        else
        {
             prev->next = next1;
        }
        prev=next1;      
    }

    for (node *new = list; new != NULL; new = new->next)
    {
        printf("%s\n",*new->word1);
    }  
}


