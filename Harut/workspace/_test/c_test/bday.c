#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <math.h>

int main()

{
   printf("enter the note: ");
   string note=get_string("");
   char freq[4]="", del[4]="";

   if (strlen(note)==6)
   {
      strncpy(freq, &note[0], 2);
      strncpy(del, &note[3], 3);
   }
   else
   {
      strncpy(freq, &note[0], 3);
      strncpy(del, &note[4], 3);
   }

   printf("freq=%s\n", freq);
   printf("del=%s\n", del);
}
