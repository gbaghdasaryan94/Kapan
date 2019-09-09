#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t  BYTE;

int main(int argc, char *argv[]) 
{


    if(argc != 2){
        fprintf(stderr,"Usage: copy infile outfile\n");
        return 1;
    }

    char *infile = argv[1];

    FILE *inptr = fopen(infile,"r");

    if(inptr == NULL) 
    {
        fprintf(stderr,"Could not open %s.\n", infile);
        return 1;
    }

    char oname[] = "A.jpeg";
    FILE *out = fopen(oname,"w");

    while(!feof(inptr)){

        BYTE tmp[512];        
        fread(tmp,sizeof(BYTE),512,inptr);
        if(tmp[0] == 0xff && tmp[1] == 0xd8 && tmp[2] == 0xff && (tmp[3] >= 0xe0 && tmp[3] <= 0xef)) {
            fclose(out);
            out = fopen(oname,"w"); 

            oname[0] =  oname[0] + 1;
            if(oname[0] == '[')
            {
                oname[0] = 'a';
            }
        }
        fwrite(tmp,sizeof(BYTE),512,out);


    }

    fclose(out);

    fclose(inptr);

    return 0;


}