// Check BMP file's info

#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: copy infile\n");
        return 1;
    }

    // remember filenames
    char *infile = argv[1];

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    BITMAPFILEHEADER new_bf;
    new_bf=bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);
    printf("bfOffBits - %u\n bfReserved1 - %hu\n bfReserved2 - %hu\n bfSize - %u\n bfType - %hu\n",bf.bfOffBits, bf.bfReserved1, bf.bfReserved2, bf.bfSize, bf.bfType);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);
    printf("biBitCount - %hu\n biClrImportant - %u\n biClrUsed - %u\n biCompression - %u\n biHeight - %d\n biPlanes - %hu\n biSize - %u\n biSizeImage - %d\n biWidth - %d\n biXPixelsPerMeter - %d\n biXPixelsPerMeter - %d\n",bi.biBitCount, bi.biClrImportant, bi.biClrUsed, bi.biCompression, bi.biHeight, bi.biPlanes, bi.biSize
    , bi.biSizeImage, bi.biWidth, bi.biXPelsPerMeter, bi.biYPelsPerMeter);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }
    printf("\n");
    // determine padding for scanlines
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        // iterate over pixels in scanline
        for (int j = 0; j < bi.biWidth; j++)
        {
            // temporary storage
            RGBTRIPLE triple;

            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
        }
        // skip over padding, if any
        fseek(inptr, padding, SEEK_CUR);
    }

    // close infile
    fclose(inptr);

    // success
    return 0;
}
