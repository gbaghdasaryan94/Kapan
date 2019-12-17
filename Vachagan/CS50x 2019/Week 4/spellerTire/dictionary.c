// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>

#include "dictionary.h"

// Represents a trie
node *root = NULL;

int total = 0;

unsigned int hash(const char letter)
{
    return (letter == '\'' ? N - 1 : tolower(letter) - 'a');
    // return (isalpha(letter) ? tolower(letter) - 'a' : N - 1);
}

node *create(void)
{
    return (node *)calloc(1, sizeof(node));
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // Open dictionary
    FILE *file = fopen(dictionary, "r");
    if (!file)
    {
        return false;
    }

    root = create();
    
    // Buffer for a word
    char word[LENGTH];

    // Insert words into trie
    while (fscanf(file, "%s", word) != EOF)
    {
        node *newNode = root;
        total++;

        for (int i = 0; word[i] != '\0'; i++)
        {
            int idx = hash(word[i]);

            if (!newNode->children[idx])
            {
                newNode->children[idx] = create();
            }
            newNode = newNode->children[idx];
        }
        newNode->is_word = true;
    }

    // Close dictionary
    fclose(file);

    // Indicate success
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return total;
}

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    node *cursor = root;

    for (int i = 0; word[i] != '\0'; i++)
    {
        cursor = cursor->children[hash(word[i])];
        if (!cursor)
        {
            return false;
        }
    }

    return cursor->is_word;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    node *temp = root;
    if (temp)
    {
        for (int i = 0; i < N; i++)
        {
            root = root->children[i];
            unload();
            root = temp;
        }
    }
    free(temp);
    return true;
}