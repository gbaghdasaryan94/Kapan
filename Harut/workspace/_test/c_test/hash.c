#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

//nodey linked arrayn a
//key hashi darakn e
//mutqagrvox anuny
typedef struct node
{
    int key;
    char name[50];
    struct node * next;
} node;

//hashy parunakum e node tipi arajin element(head) ev count
typedef struct hash
{
    node * head;
    int count;
} hash;

hash * hashTable = NULL;
int hashSize = 0;

//mutqagrvac anuny sarqum e int key
int stringToKey(char name[])
{
    int key=0;
    for (int i=0; name[i] != '\0'; i++)
    {
        key += name[i];
    }
    return key % hashSize;
}

//stexcum e nor node
node * createNode(int key, char * name)
{
    node * newnode = (node *)malloc(sizeof(node));
    newnode -> key = key;
    strcpy(newnode -> name, name);
    newnode -> next = NULL;
    return newnode;
}

//
void insertToHash(int key, char * name)
{
    node * newnode = createNode(key, name);
    if (!hashTable[key].head)
    {
        //ete datark e hash-i key-y darnum e newnode
        hashTable[key].head = newnode;
        hashTable[key].count = 1;
        return;
    }
    newnode -> next = (hashTable[key].head);
    hashTable[key].head = newnode;
    hashTable[key].count++;
}

void printHash()
{
    node * myNode;
    for (int i=0; i<hashSize; i++)
    {
        if (!hashTable[i].count)
        continue;
        myNode = hashTable[i].head;
        printf("Hash Table index %i\nHash ID Name\n--------------\n", i);

        while(myNode != NULL)
        {
            printf("%-12d%-14s\n", myNode -> key, myNode -> name);
            myNode = myNode -> next;
        }
    }
    return;
}

//________________________________________________
int main()
{
    char * name;
    hashSize = get_int("Enter the name of elements: ");
    hashTable = (hash *)calloc(hashSize, sizeof(hash));

    while (true)
    {
        printf("\n1 Insert\t2. Print All \n");
        int ch =  get_int("Enter your choise: ");

      switch (ch)
        {
            case 1:
                name = get_string("Name: ");
                insertToHash(stringToKey(name), name);
                break;

            case 2:
                printHash();
                break;

            default:
                break;
        }
    }

    name = get_string("Name: ");
    insertToHash(stringToKey(name), name);
    printHash();
}