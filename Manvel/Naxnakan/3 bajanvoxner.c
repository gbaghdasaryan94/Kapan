#include <stdio.h>
#include <cs50.h>

int main(void)
{   
    int  count = 0;
    int n = get_int ("skizb: ");
    int m = get_int ("verj: ");
    for(int i=n;i<m;i++)
    {   
        if(i!=0)
        {
            if(i%3==0)
            {
                count++;
            }
        }
    }

    printf("Ereq-i bajanvogh %i tiv ka\n",count);


}