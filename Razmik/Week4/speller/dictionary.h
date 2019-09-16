// Declares a dictionary's functionality

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdbool.h>

// Maximum length for a word
// (e.g., pneumonoultramicroscopicsilicovolcanoconiosis)
#define LENGTH 45
#define DICTIONARY "dictionaries/large"

typedef struct nevi
{
    int id;
    char * word;
    struct nevi * next;

} Node;


// Prototypes
bool check(const char *word);
bool load(const char *dictionary);
unsigned int size(void);
bool unload(void);
void addto(char * wrd);

#endif // DICTIONARY_H
