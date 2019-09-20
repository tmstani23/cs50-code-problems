#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    //Pointer to input file
    char *infile = argv[2];

     // check for 3 command line arguments
    if (argc != 2)
    {
        fprintf(stderr, "./resize n infile outfile");
        return 1;
    }

    // open input file
    FILE *inptr = fopen(infile, "r");
    //throw error if file fails to open
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }


    //free any mallocs (free(pointer))
    
    return 0;
}
