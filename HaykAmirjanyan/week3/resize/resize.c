// Copies a BMP file

#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: copy infile outfile\n");
        return 1;
    }

    // remember filenames
    int n = atoi(argv[1]);
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

    int oldHeight = abs(bi.biHeight);
    bi.biHeight = bi.biHeight * n;
    int oldWidth = bi.biWidth;
    bi.biWidth = bi.biWidth * n;

    // determine padding for scanlines
    int padding = (4 - (oldWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int newPadding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // determine new bisizeImage & bfSize
    bi.biSizeImage = ((sizeof(RGBTRIPLE) * oldWidth) + newPadding) * oldHeight;
    bf.bfSize = bi.biSizeImage + 54;

     // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // iterate over infile's scanlines
    for (int i = 0; i < oldHeight; i++)
    {
        // temporary storage
        RGBTRIPLE triple[oldWidth];

        // iterate over pixels in scanline
        for (int j = 0; j < oldWidth; j++)
        {
            // read RGB triple from infile
            fread(&triple[j], sizeof(RGBTRIPLE), 1, inptr);
        }

        for(int l = 0; l < n; l++){
            for(int m = 0; m < oldWidth; m++){
                for(int z = 0; z < n; z++){

                    // write RGB triple to outfile
                    fwrite(&triple[m], sizeof(RGBTRIPLE), 1, outptr);   
                }       
            }
             // then add it back (to demonstrate how)
                for (int k = 0; k < newPadding; k++)
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
