#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cs50.h>

typedef struct node {
    int key, age;
    char name[100];
    struct node *next;
}node;

typedef struct hash {
    node *head;
    int count;
}hash;

hash *hashTable = NULL;
int hashSize = 0;

node * createNode(int key, char *name, int age) {
    node *newnode;
    newnode = (node *)malloc(sizeof(node));
    newnode->key = key;
    newnode->age = age;
    strcpy(newnode->name, name);
    newnode->next = NULL;
    return newnode;
}

int stringToKey(char name[]){
    int key = 0;
    for (int i = 0; name[i] != '\0'; i++)
        key += name[i];
    return key % hashSize;
}

void insertToHash(int key, char *name, int age) {

    node *newnode =  createNode(key, name, age);

    if (!hashTable[key].head) {
        hashTable[key].head = newnode;
        hashTable[key].count = 1;
        return;
    }
    
    newnode->next = (hashTable[key].head);
    
    hashTable[key].head = newnode;
    hashTable[key].count++;
    return;
}


void deleteFromHash(int key, char *name) {
    int flag = 0;
    node *temp, *myNode;

    myNode = hashTable[key].head;
    if (!myNode) {
        printf("Given data is not present in hash Table!!\n");
        return;
    }

    temp = myNode;
    while (myNode != NULL) {
        if (!strcmp(myNode->name, name)) {
            flag = 1;
            if (myNode == hashTable[key].head)
                    hashTable[key].head = myNode->next;
            else
                    temp->next = myNode->next;

            hashTable[key].count--;
            free(myNode);
            break;
        }
        temp = myNode;
        myNode = myNode->next;
    }
    if (flag)
        printf("Data deleted successfully from Hash Table\n");
    else
        printf("Given data is not present in hash Table!!!!\n");
    return;
}

void searchInHash(int key, char *name) {
    int flag = 0;
    node *myNode;
    myNode = hashTable[key].head;
    if (!myNode) {
        printf("Search element unavailable in hash table\n");
        return;
    }
    while (myNode != NULL) {
        if (!strcmp(myNode->name, name)) {
            printf("Hash ID  : %d\n", myNode->key);
            printf("Name     : %s\n", myNode->name);
            printf("Age      : %d\n", myNode->age);
            flag = 1;
            break;
        }
        myNode = myNode->next;
    }
    if (!flag)
        printf("Search element unavailable in hash table\n");
    return;
}

void display() {
    node *myNode;
    int i;
    for (i = 0; i < hashSize; i++) {
        if (!hashTable[i].count || !hashTable[i].head)
            continue;
        myNode = hashTable[i].head;
        
        printf("\nData at index %d in Hash Table:\n"
                "Hash ID     Name          Age   \n"
                "--------------------------------\n", i);
        while (myNode != NULL) {
            printf("%-12d%-15s%d\n", myNode->key, myNode->name, myNode->age);
            myNode = myNode->next;
        }
    }
    return;
}

int main() {
    char * name;
    int age;

    hashSize = get_int("Enter the number of elements: ");
    hashTable = (hash *)calloc(hashSize, sizeof (hash));

    while (true) {
        printf("\n1. Insert\t2. Delet\n");
        printf("3. Search\t4. Print All\n5. Exit\n");

        int ch = get_int("Enter your choice: ");

        switch (ch) {
            case 1:
                name = get_string("Name: ");
                age = get_int("Age:");
                insertToHash(stringToKey(name), name, age);
                break;
            case 2:
                name = get_string("Enter the value to perform deletion:");
                deleteFromHash(stringToKey(name), name);
                break;
            case 3:
                name = get_string("Enter the key to search:");
                searchInHash(stringToKey(name), name);
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("You have entered wrong option!!\n");
                break;
        }
    }
    return 0;
}