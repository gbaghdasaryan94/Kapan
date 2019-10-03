#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: copy infile outfile\n");
        return 1;
    }
    FILE *card = fopen(argv[1], "r");
    if (card == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", argv[1]);
        return 2;
    }

    FILE *images = fopen(argv[1], "r");
    char image[10];
    int count = 0;
    BYTE *buffer = malloc(512);
    fseek(card, 0, SEEK_END);
    int fsize = ftell(card);
    rewind(card);

    while (ftell(card) != fsize)
    {
        fread(buffer, 1, 512, card);
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            fclose(images);
            sprintf(image, "%03i.jpg", count);
            images = fopen(image, "w");
            if (images == NULL)
            {
                exit(1);
            }
            count++;
        }
        fwrite(buffer, 1, 512, images);
    }
    fclose(images);
    fclose(card);
    free(buffer);
}

