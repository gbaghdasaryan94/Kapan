
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <cs50.h>

typedef struct node{
    int key;
    char name[50];
    struct node *next;
} node;

typedef struct hash {
    node *head;
    int count;
}hash;

hash *hashTable = NULL;
int hashSize =0;

int stringToKey(char name[]){
    int key =0;
    for (int i=0; name[i] !='\0';i++){
        key +=name[i];
    }
    return key%hashSize;
}

node * createNode(int key, char *name){
    node *newnode=(node*)malloc(sizeof(node));
    newnode->key =key;
    strcpy(newnode->name, name);
    newnode->next = NULL;
    return newnode; 
}



void insertToHash(int key, char *name){
    node *newnode = createNode(key, name);
    if(!hashTable[key].head){
        hashTable[key].head=newnode;
        hashTable[key].count=1;
        return;
    }
    newnode -> next = (hashTable[key].head); 
    hashTable[key].head = newnode;
    hashTable[key].count++;
}

void printHash(){
    node *myNode;

    for(int i=0;i<hashSize; i++){
        if(!hashTable[i].count)
            continue;

        myNode = hashTable[i].head;
        printf("hash Table index  %i \n Hash ID Name \n -----------\n",i);    

        while(myNode != NULL){
            printf("%-14d%s\n", myNode->key, myNode->name);
            myNode=myNode->next;
        } 
    }
}


int main(){
    char *name;
    hashSize=get_int("Enter the number of elements\n");
    hashTable=(hash *)calloc(hashSize, sizeof(hash));


    while(ch){
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