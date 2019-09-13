// Copies a BMP file

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
    char *infile = argv[2];
    char *outfile = argv[3];
    int n = atoi (argv[1]);

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



    BITMAPFILEHEADER new_bf;
    BITMAPINFOHEADER new_bi;
    new_bf = bf;
    new_bi=bi;
    new_bi.biHeight = bi.biHeight * n;
    new_bi.biWidth = bi.biWidth * n;

  printf ("%i\n", new_bi.biHeight);
  printf ("%i\n", new_bi.biWidth);



    // determine padding for scanlines
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int padding2 = (4 - (new_bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    new_bi.biSizeImage = ((sizeof(RGBTRIPLE)*new_bi.biWidth)+ padding2)* abs(new_bi.biHeight);
    new_bf.bfSize = new_bi.biSizeImage +sizeof(BITMAPFILEHEADER)+sizeof(BITMAPINFOHEADER);


    // write outfile's BITMAPFILEHEADER
    fwrite(&new_bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&new_bi, sizeof(BITMAPINFOHEADER), 1, outptr);
/*
    printf("%i\n", padding);
    printf("%i\n", padding2);
    printf("%i\n", new_bi.biSizeImage);
    printf("%i\n" , new_bf.bfSize);
*/
    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {

        RGBTRIPLE line[bi.biWidth];


        // iterate over pixels in scanline
        for (int j = 0; j < bi.biWidth; j++)
        {
            // read RGB triple from infile
            fread(&line[j], sizeof(RGBTRIPLE), 1, inptr);

        }

        for (int x=0; x<n; x++) // repeat the line
        {
            for (int y =0; y < bi.biWidth; y++) //get each element from array
            {
                for (int z = 0; z<n; z++) // to repeat the elemnt from above n times
                {
                    fwrite(&line[y], sizeof(RGBTRIPLE), 1, outptr);
                }
            }
            for (int k = 0; k < padding2; k++)
            {
                fputc(0x00, outptr);
            }
        }

        // skip over padding, if any
        fseek(inptr, padding, SEEK_CUR);

    }


        // then add it back (to demonstrate how)


    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}
