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

    //input resize
    int resize=atoi(argv[1]);

    if (resize<1)
    {
        fprintf(stderr, "Usage: invalid size \n");
        return 1;
    }

    // remember filenames
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
    printf("bfsize %i bisizeimage %i\n" ,bf.bfSize, bi.biSizeImage);
    printf("bfWidth %i  biHight  %i \n" , bi.biWidth, bi.biHeight);

    int padd = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    printf(" padd %i \n", padd);

       
    int biHeight = bi.biHeight;
    int biWidth=bi.biWidth;
    
    

    // find new image sizes
    bi.biWidth *=resize;
    bi.biHeight *=resize;
   
   // determine padding for scanlines
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    printf(" padding %i \n", padding);
   
    bi.biSizeImage=((sizeof(RGBTRIPLE)*bi.biWidth)+padding)*abs(bi.biHeight);
    bf.bfSize=bi.biSizeImage+sizeof(BITMAPFILEHEADER)+sizeof(BITMAPINFOHEADER);
    printf("bfsize %i bisizeimage %i\n" ,bf.bfSize, bi.biSizeImage);
    printf("bfWidth %i  biHight  %i \n" , bi.biWidth, bi.biHeight);

    
    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    RGBTRIPLE trip[bi.biWidth];

    // iterate over infile's scanlines
    for (int i = 0; i < abs(biHeight); i++)
    {
        int t=0;
        // iterate over pixels in scanline
        for (int j = 0; j < biWidth; j++)
        {
    
            // temporary storage
            RGBTRIPLE triple;
            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
            
            // write RGB triple to outfile
            for (int r2=0;r2<resize; r2++)
            {
                fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                trip[t++]=triple;
            }    
        }
        // skip over padding, if any
        for (int k = 0; k < padding; k++)
                fputc(0x00, outptr);
        
        for (int r1=0; r1<resize-1; r1++)
        {
            for (int r2=0; r2<t;r2++)
                fwrite(&trip[r2], sizeof(RGBTRIPLE), 1, outptr);
            for (int k = 0; k < padding; k++)
                fputc(0x00, outptr);
        }
            fseek(inptr, padd, SEEK_CUR);
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}