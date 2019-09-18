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
    return (letter == '\'' ? N-1 : tolower(letter) - 'a');
}

node *create(void)
{
    node *newNode = malloc(sizeof(node));
    if(newNode==NULL)
    {
        unload();
        return false;
    }
    newNode->is_word = false;
    return newNode;
}

void freeRoot(node *temp)
{
    for(int i = 0; i < N; i++)
    {
        if (!temp -> children[i])
        {
            freeRoot(temp -> children[i]);
        }
    }
    free(temp);
    return;
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
        
        for (int i = 0; word[i] != '\0'; i++){
            int idx = hash(word[i]); 
            
            if (!newNode->children[idx]){
                newNode->children[idx] = create();
            }
            newNode = newNode->children[idx];

            if (!newNode)
            {
                unload();
                fclose(file);
                return true;
            }
        }
        newNode->is_word = true;
        total++;
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
bool unload(void){
    // node *cursor;// = root;
    // for (int i = 0; i < N; i++)
    // {
    //     cursor = root->children[i];
    //     if (cursor){
    //         unload();
    //     }
            
    // }
    // free(cursor);
    freeRoot(root);
    return true;
}