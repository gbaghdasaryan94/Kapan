#include <string.h>
#include <stdio.h>
#include <cs50.h>


typedef struct node
{
    char word1[10];
    struct node* next;
}
node;

int main(void)
{
    int length = get_int("Length: ");
    node *nextt, *prev, *list;

    list = NULL;

    for(int i=0; i<length; i++)
    {
        nextt = malloc(sizeof(node));
        *nextt->word1 = '\0';
        nextt->next = NULL;

        if(list == NULL)
        {
            list = nextt;
        }
        else
        {
            prev->next = nextt;
        }
        prev=nextt;        
    }        
    

    // int n = get_int("Test: ");

    // for (myvariable *new = list; new != NULL; new = new->ptr)
    // {
    //     if(new->a==n)
    //     {
    //         printf("%i\n",new->a);
    //         break;
    //     }
    // }

}
