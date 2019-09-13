#include <string.h>
#include <stdio.h>
#include <cs50.h>


typedef struct node
{
    char word1[10];
    struct node* ptr;
}
node;

int main(void)
{
    int length = get_int("Length: ");
    node *next, *prev, *list;

    list = NULL;

    for(int i=0; i<length; i++)
    {
        next = malloc(sizeof(node));
        *next->word1 = *get_string("word: ");
        next->ptr = NULL;

        if(list == NULL)
        {
            list = next;
        }
        else
        {
            prev->ptr = next;
        }
        prev=next;        
    }

    for (node *new = list; new != NULL; new = new->ptr)
    {
        printf("%s\n",new->word1);
    }

}
