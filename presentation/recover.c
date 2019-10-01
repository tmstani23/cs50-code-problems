#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    

     // check for 2 command line arguments
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image");
        return 1;
    }
    //Pointer to input file
    char *infile = argv[1];

    // open input file
    FILE *inptr = fopen(infile, "r");
    // char array to store filename
    char filename[10]; 
    //pointer to image file
    FILE *img;
    int fileNameCount = -1;
    //throw error if file fails to open
    
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    //initialize flag to state when jpeg has been found or not
    int foundJpeg = 0;

    //Initialize loop condition
    int notEndOfFile = 0;
    //loop until end of file
    do {
        //initialize buffer to hold blocks of bytes from memory card
        unsigned char buffer[512];
        
        
        //read 512 bytes into buffer
        int readVar = fread(buffer, 512, 1, inptr);
        
        //if start of jpeg
        if (buffer[0] == 0xff &&
            buffer[1] == 0xd8 &&
            buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0) 
        {
            
            printf("found start of jpeg\n");
            printf("found jpeg status: %i", foundJpeg);
            
            //already found a jpeg? found a new jpeg
            //printf("foundJpeg = %i\n", foundJpeg);
            if(foundJpeg == 1) {
                //yes - 
                //close previous file
                //update filename count
                fileNameCount++;
                //create new file
                //set to 000.jpeg if first file
                sprintf(filename, "%03i.jpg", fileNameCount);
                printf("file created: %s\n", filename); 
                //open new file
                img = fopen(filename, "w");
                // write 512 bytes to file
                fwrite(buffer, 512, 1, img);
                //added to cancel infinite loop, remove once not needed
                //notEndOfFile = 1;
            }
            //no - first jpeg found
            else {
                
                //update filename count
                fileNameCount++;
                //create new filename
                sprintf(filename, "%03i.jpg", fileNameCount);
                printf("file created: %s\n", filename); 
                //open new file
                img = fopen(filename, "w");
                // write 512 bytes to file
                fwrite(buffer, 512, 1 , img);
                //set found jpeg  to true
                foundJpeg = 1;
            }
            
            
                
        }
        //if not start of jpeg
        else {
            printf("not start of jpeg");
            //calculate size of last item in buffer
            //already found a jpeg?
            if(foundJpeg == 1) {
                //yes 
                    //is next block less than 512 bytes?
                    //size_t numberOfElements = sizeof(buffer)/sizeof(buffer[0]);
                    printf("buffer size in bytes: %lu\n", sizeof(buffer));
                    printf("buffer: %i", buffer[0]);
                   // printf("number of elems in buffer: %zu\n", numberOfElements);
                    printf(" number of elems read %i\n", readVar);
                    //yes - end of file
                    if (readVar != 1) 
                    {
                        printf("end of file found\n");
                        //close files
                        fclose(img);
                        //update while loop condition to end loop
                        notEndOfFile = 1;
                    }
                    
                    //no - //- write next 512 bytes to file
                    fwrite(buffer, 512, 1 , img);
                        
                    
            }
            //havent yet found a jpeg and not start of a jpeg
            //discard 512 bytes and return to start of loop
               
                    
                
        }
            
        
        
    }
    while (notEndOfFile != 1);
   
    printf("finished\n");
    //free any mallocs (free(pointer))
    
    return 0;
}
