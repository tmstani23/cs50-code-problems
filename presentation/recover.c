#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    

     // check for 2 command line arguments
    if (argc != 2)
    {
        fprintf(stderr, "./resize n infile outfile");
        return 1;
    }
    //Pointer to input file
    char *infile = argv[1];

    // open input file
    FILE *inptr = fopen(infile, "r");
    // char array to store filename
    char filename[5]; 
    int fileNameCount = 0;
    //throw error if file fails to open
    
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    //Initialize loop condition
    int notEndOfFile = 0;
    //loop until end of file
    do {
        //initialize buffer to hold blocks of bytes from memory card
        unsigned char buffer[550];
        //initialize flag to state when jpeg has been found or not
        int foundJpeg = 0;

        //testing filename creation based on count
        //sprintf(filename, "%03i.jpg", filenameCount);
        //printf("filename: %s\n", filename); 
        
        //read 512 bytes into buffer
        fread(buffer, 512, 1, inptr);
        
        //if start of jpeg
        if (buffer[0] == 0xff &&
            buffer[1] == 0xd8 &&
            buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0) 
        {
            
            printf("found start of jpeg\n");
            //already found a jpeg?
            if(foundJpeg == 1) {
                //yes - 
                //close previous file
                //update filename count
                //create new file
                //update filename to 002.jpg
                //sprintf(filename, "%03i.jpg", filenameCount);
                //printf("filename: %s\n", filename); 
                //open new file
                
                // write 512 bytes to file
            }
            //no
            else if (foundJpeg == 0) {
                //update filename count
                //fileNameCount++;
                //create new file
                    //update filename to 002.jpg
                //sprintf(filename, "%03i.jpg", filenameCount);
                // write 512 bytes to file

                //set found jpeg  to true
                foundJpeg = 1;
            }
            
            
                
        }

        else {
            //printf("not start of jpeg");
            //if not start of jpeg
            //already found a jpeg?
            if(foundJpeg == 1) {
                //yes 
                    //is next block less than 512 bytes?
                        //yes - end of file
                            //close files
                            //update while loop condition to end loop
                            notEndOfFile = 1;
                        //no - //- write next 512 bytes to file
            }
                
                    
                //no - discard 512 bytes and return to start of loop
        }
            
        
        
    }
    while (notEndOfFile != 1);
        
    
    
   
    
    //free any mallocs (free(pointer))
    
    return 0;
}
