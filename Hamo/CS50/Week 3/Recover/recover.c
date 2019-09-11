#include <stdio.h>
#include <stdlib.h>

int main(void)
{               

unsigned char buff[512] = {0};
char jpgName[8] = {0};
int count = 1;
FILE* out = NULL;

FILE* inp = fopen("card.raw", "r");

if (inp == NULL)
{
    printf("Could not open card.raw \n");
    return 1;
}   


while(fread(buff, sizeof(buff), 1, inp) )
{                                   

        if(buff[0] == 0xff && buff[1] == 0xd8 && buff[2] == 0xff && (buff[3] >= 0xe0 && buff[3] <= 0xef))
        {   
            if(out)                   
            {
              fclose(out);
              out=NULL;
            }

            sprintf(jpgName,"%d.jpg", count);

            out = fopen(jpgName, "w");         
            
            if (out==NULL)
            {
              printf("Could not open %s.\n", jpgName);
              return 1;
            }               

            
            fwrite(buff, sizeof(buff), 1, out);

            count++;
         }
          else 
         {

             if(out)
                fwrite(buff, sizeof(buff), 1, out);                              
         }   
    }

    
      fclose(out);    
      fclose(inp);

    return 0; 
}