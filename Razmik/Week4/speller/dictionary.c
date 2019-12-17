// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <ctype.h>
#include "dictionary.h"

Node *ndict[26];
int count = 0;

// Returns true if word is in dictionary else false
bool check(const char *wrd)
{
    int i = tolower(wrd[0]) - 97;
    Node *srch = ndict[i];
    while (srch != NULL)
    {
        // printf("%s -- ", srch->word);
        if (!strcasecmp(wrd, srch->word))
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
    FILE *fdic = fopen(dictionary, "r");
    if (fdic == NULL)
    {
        return false;
    }
    char gword[LENGTH];
    while (fgets(gword, sizeof(gword), fdic))
    {
        gword[strlen(gword) - 1] = '\0';
        addto(gword);
        count++;
    }
    fclose(fdic);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return count;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int i = 0; i < 26; i++)
    {
        while (ndict[i])
        {
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
    int i = tolower(wrd[0]) - 97;
    Node *d = malloc(sizeof(Node));
    strcpy(d->word, wrd);
    d->next = ndict[i];
    ndict[i] = d;
}