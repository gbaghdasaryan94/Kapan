#include <stdio.h>
#include <cs50.h>
#include <stdint.h>

#define BLOCK_SIZE 512

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{

    if (argc != 2)
    {
        fprintf(stderr, "Usage: recover [*.raw]\n");
        return 1;
    }

    char *infile = argv[1];
    FILE *inptr = fopen(infile, "r");

    if (inptr == NULL)
    {
        fprintf(stderr, "Error ... %s.\n", infile);
        return 2;
    }

    BYTE buffer[512];
    int count = 0;
    char filename[8];
    FILE *outptr = NULL;

    while (!feof(inptr))
    {

        int bytes = fread(buffer, sizeof(BYTE), BLOCK_SIZE, inptr);

        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (outptr)
            {
                fclose(outptr);
            }

            sprintf(filename, "%03i.jpg", count++);
            outptr = fopen(filename, "w");
        }

        if (outptr)
        {
            fwrite(buffer, sizeof(BYTE), bytes, outptr);
        }
    }
    fclose(outptr);
    fclose(inptr);
}