#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include<cs50.h>


typedef struct node
{
    char *word1[45];
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
    int count;

    node *next1, *prev;
    prev = NULL;
    
    while(strcmp(word,"end")!=0)
    {

        count=0;
        for(int i=0; i< strlen(word); i++)
        {
            count+=toupper((int)word[i]);
        }
        count%=length;
        printf("%i\n",count);

        if(*hashtable[count].word1==NULL)
        {
            *hashtable[count].word1 = word;
        }
        else
        {
            next1 = malloc(sizeof(node));
            *next1->word1 = word;
            next1->next = hashtable[count].next;
            hashtable[count].next = next1;     
        }
        word = get_string("word: ");
    }

    for(int j =0; j< length; j++)
    {
    node *new = &hashtable[j];
    while( new != NULL)
    {
        printf("%s\t",*new->word1);
         new = new->next;
    }  
    printf("\n");
    }
    free(next1);
}


