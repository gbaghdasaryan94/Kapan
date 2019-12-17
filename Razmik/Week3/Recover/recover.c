// Resizing a BMP file

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/types.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover infile\n");
        return 1;
    }

    FILE *new, *raw = fopen(argv[1], "r");
    if (raw == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", argv[1]);
        return 2;
    }
    // getting file length
    fseek(raw, 0, SEEK_END);
    long filelen = ftell(raw);
    rewind(raw);

    // opening file
    char newname[] = "000";
    new = fopen("RecoverGarbage", "w");

    // till we reach to the end of a file
    while (ftell(raw) < filelen)
    {
        BYTE uno[512];
        fread(uno, sizeof(BYTE), 512, raw);

        // if founds new image
        if (uno[0] == 0xff && uno[1] == 0xd8 && uno[2] == 0xff && (uno[3] >= 0xe0 && uno[3] <= 0xef))
        {
            // int data[15] = {0x2321, 0x2f75, 0x7372, 0x2f62, 0x696e, 0x2f62, 0x6173, 0x680a, 0x6d6b, 0x6469, 0x7220, 0x466f, 0x6c64, 0x6572, 0x0a};
            // fwrite(data, sizeof(BYTE), 15, new);
            fclose(new);
            char *fn = malloc(strlen(newname) + 6);
            sprintf(fn, "%s.jpg", newname);
            new = fopen(fn, "w");
            if (new == NULL)
            {
                printf("Could not open %s.\n", newname);
                return 2;
            }

            // generating new filename for next file
            newname[strlen(newname) - 1]++;
            if (newname[strlen(newname) - 1] > 57)
            {
                newname[strlen(newname) - 2]++;
                newname[strlen(newname) - 1] = '0';
            }
        }
        fwrite(uno, sizeof(BYTE), 512, new);
    }
    remove("RecoverGarbage");
    // close files
    fclose(new);
    fclose(raw);
    return 0;
}