// Resizing a BMP file

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: ./copy [X times] [infile] [outfile]\n");
        return 1;
    }

    // remember filenames and resize time
    float f = atof(argv[1]);
    char *infile = argv[2];
    char *outfile = argv[3];

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    // determine padding for scanlines
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // getting infile height
    int oldHeight = abs(bi.biHeight);

    // getting infile width
    int oldWidth = bi.biWidth;

    // changing width
    bi.biWidth = bi.biWidth * f;

    // changing Height
    bi.biHeight = bi.biHeight * f;

    // getting outfile padding
    int opadding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // getting outfile Image Size
    bi.biSizeImage = ((sizeof(RGBTRIPLE) * bi.biWidth) + opadding) * abs(bi.biHeight);

    // getting outline file size
    bf.bfSize = bi.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);
    
    int lim = ceil(1 / f), q = ceil(f);
    // iterate over infile's scanlines
    for (int i = 0; i < oldHeight; i++)
    {
        // temporary array for every line
        RGBTRIPLE rgbs[oldWidth];

        // read RGB triple from infiles' line
        for (int j = 0; j < oldWidth; j++)
        {
            fread(&rgbs[j], sizeof(RGBTRIPLE), 1, inptr);
        }

        // write for every line
        for (int b = 0; i % lim == 0 && b <  q; b++)
        {
            // write RGB triple to outfile
            for (int l = 0; l < bi.biWidth; l++)
            {
                fwrite(&rgbs[(int)(l / f)], sizeof(RGBTRIPLE), 1, outptr);
            }

            // add padding to outfile
            for (int k = 0; k < opadding; k++)
            {
                fputc(0x00, outptr);
            }
        }

        // skip over padding, if any
        fseek(inptr, padding, SEEK_CUR);
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}