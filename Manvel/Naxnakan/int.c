#include <cs50.h>
#include <stdio.h>

int add_two_ints(int a,int b);
int main(void)
{
    printf("ask me the integer: ");
    int x = get_int("");
    printf("ask another integer: ");
    int y = get_int("");

    int z = add_two_ints(x,y);

    printf("the sum of %i and %i is %i\n",x,y,z);


}