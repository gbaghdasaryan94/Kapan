// Declares a dictionary's functionality

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdbool.h>

// Maximum length for a word
// (e.g., pneumonoultramicroscopicsilicovolcanoconiosis)
#define LENGTH 47
#define DICTIONARY "dictionaries/large"

typedef struct nevi
{
    char word[LENGTH];
    struct nevi *next;

} Node;

// Prototypes
bool check(const char *wrd);
bool load(const char *dictionary);
unsigned int size(void);
bool unload(void);
void addto(char *wrd);


#endif // DICTIONARY_H
