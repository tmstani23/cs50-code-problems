// Copies a BMP file

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "bmp.h"

int main(int argc, char *argv[])
{
    // check for 3 command line arguments
    if (argc != 4)
    {
        fprintf(stderr, "./resize n infile outfile");
        return 1;
    }
    
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        
        //check if input string includes any nondigits
        if(isdigit(argv[1][i]) == 0) 
        {
            //throw error if so
            printf("Usage: n must be a number\n");
            return 1;
        }
      
    }


    // remember filenames and command line args
    int n = atoi(argv[1]);
    
    char *infile = argv[2];
    char *outfile = argv[3];  

    //throw error if first argument isn't a positive number between 1 and 100
    if(n < 1 || n > 100) 
    {
        printf("n in loop: %i\n", n);
        printf("n must be a positive integer between 1 and 100: %i\n", n);
        return 1;
    } 

   

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

    int oldpadding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    //modify bmheader and infoheader size/width/height here:
    bi.biHeight *= n;
    bi.biWidth *= n;
    //bi.biSize *= n;
    //bf.bfSize *= n;

    printf("size in bytes of bitmap file = %i\n", bf.bfSize);
    printf("biWidth = %i\n", bi.biWidth);
    printf("biHeight = %i\n", bi.biHeight);
    printf("number of bytes of structure = %i\n", bi.biSize);
    printf("number of bits per pixel = %i\n", bi.biBitCount);
    printf("byte size of the image = %i\n", bi.biSizeImage);
    
    // determine padding for scanlines
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // determine image size and structure size
    bi.biSizeImage = ((sizeof(RGBTRIPLE) * bi.biWidth) + padding) * abs(bi.biHeight);
    bf.bfSize = bi.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
    
    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);


    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {

        // store scanline in an array pixel by pixel for vertical scaling.
        RGBTRIPLE scanline[bi.biWidth];

        // iterate over pixels in scanline
        for (int j = 0; j < bi.biWidth; j++)
        {
            //check if we've hit padding in original bmp.
            if (j % oldpadding == 0 && j != 0) 
            {
                //skip the padding.
                fseek(inptr, oldpadding, SEEK_CUR);
            }

            // temporary storage
            RGBTRIPLE triple;

            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

            scanline[j] = triple;
            printf("%c\n", scanline[j]);

        }

        for (int y = 0; y < n; y++) // repeat each row n times
        {
            for (int x = 0; x < bi.biWidth; x++) // iterate over pixels
            {
                for (int r = 0; r < n; r++) // repeat each pixel n times
                    fwrite(&scanline[x], sizeof(RGBTRIPLE), 1, outptr);
            }
            // write padding if any for current scanline.
            for (int z = 0; z < padding; z++)
            {
                fputc(0x00, outptr);
            }
        }
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    //free any mallocs (free(pointer))

    // success
    return 0;
}
