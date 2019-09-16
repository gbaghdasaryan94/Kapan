// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "dictionary.h"


Node * ndict[26] = {NULL};

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    char str[46];
    strcpy(str,word);
    for(int i=0;i<=strlen(str);i++)
        if(str[i]>=65 && str[i]<=92)
            str[i]=str[i]+32;
    int i = str[0] - 97;
    Node * srch = ndict[i];
    while (srch != NULL)
    {
        if (strcmp(srch->word,&str[0])==0)
        {
            return true;
        }
        srch = srch->next;
    }
    return false;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    FILE * fdic = fopen(dictionary, "r");
    if (fdic == NULL)
    {
        return false;
    }
    char ch = getc(fdic);
    char gword[45];
    int index = 0;
    while (ch != EOF)
    {
        if (ch != '\n')
        {
            gword[index++]=ch;
        }
        else
        {
            addto(gword);
            memset(gword, 0, sizeof gword);
            index = 0;
        }
        ch = getc(fdic);
    }
    return true;
}


// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    int count = 0;
    for(int i = 0; i<26; i++)
    {
        Node * size = ndict[i];
        while (size != NULL)
        {
            count++;
            size = size->next;
        }
    }
    return count;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // printf("They started distroying me, honey... Promise you'll never forget me ~\n");
    for (int i=0; i<26; i++)
    {
        while(ndict[i]){
            Node *n1 = ndict[i];
            ndict[i] = ndict[i]->next;
            free(n1);
        }
    }
    return true;
}

// Adds words to short-linked list array
void addto(char *wrd)
{
    int i = wrd[0] - 97;
    if ( ndict[i] == NULL )
    {
        ndict[i] = (Node *)malloc(sizeof(Node *));
        *ndict[i] = (Node){ 1, "zulum", NULL };
        return;
    }
    Node * d = ndict[i];
    ndict[i] = (Node *)malloc(sizeof(Node *));
    ndict[i]->word = malloc(sizeof(char) * (strlen(wrd) + 1));
    strcpy(ndict[i]->word, wrd);
    ndict[i]->id = d->id + 1;
    ndict[i]->next = (Node *)malloc(sizeof(Node *));
    ndict[i]->next = d;
}