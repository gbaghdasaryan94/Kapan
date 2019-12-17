// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>

#include "dictionary.h"

node *hashtable[N];
int totalWords = 0;

unsigned int hash(const char *word)
{
    return tolower(word[0]) - 'a';
}

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    int index = hash(word);

    node *cursor = hashtable[index];

    while (cursor)
    {
        if (!strcasecmp(word, cursor->word))
        {
            return true;
        }
        cursor = cursor->next;
    }

    return false;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{

    FILE *file = fopen(dictionary, "r");
    if (!file)
    {
        unload();
        return false;
    }

    char word[LENGTH + 1];

    while (fscanf(file, "%s", word) != EOF)
    {   
        totalWords++;
        node *new_node = malloc(sizeof(node));

        strcpy(new_node->word, word);

        int letter = hash(word);

        new_node->next = hashtable[letter];
        hashtable[letter] = new_node;
    }

    fclose(file);

    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return totalWords;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *cursor = hashtable[i];

        while (cursor)
        {
            node *temp = cursor;
            cursor = cursor->next;
            free(temp);
        }

        free(cursor);
    }

    return true;
}