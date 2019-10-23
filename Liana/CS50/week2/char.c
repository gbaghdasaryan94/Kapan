#include  <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>


int main(void)
{
    string name = get_string ("Name=");
    char initials [4];  
    int n= strlen (name);
    int counter=0;
    for (int i=0; i< n; i++ )
      { 
        if (isupper(name[i])) 
           {
            initials [counter]=name[i]; 
            counter++;  
           }     
      } 
    initials[counter]= '\0';  
    printf("%s\n", initials);  
}         