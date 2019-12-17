#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: copy infile outfile\n");
        return 1;
    }
 
    FILE *raw_file = fopen(argv[1], "r");

    if (raw_file == NULL)
    {
        fprintf(stderr, "Could not open \n");
        return 2;
    }
    
    int j_f=0;
    uint8_t *buffer = malloc(512);
    FILE *image;
    
    while (fread(buffer, 512  , 1, raw_file))
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
           // create filename
            char image_file[10];
            sprintf(image_file, "%03i.jpg", j_f);

            // open new image file
            image = fopen(image_file, "w");

            // check file is created
            if (image == NULL)
            {
                fclose(raw_file);  
                return 3;
            }
            j_f++;
        }
        // if first jpg is not found, continue
        if (j_f==0)  continue;
        
        // write into jpg file
        fwrite(buffer, 512, 1, image);
    }

    fclose(raw_file);
    fclose(image);
    free(buffer);
    return 0;
}