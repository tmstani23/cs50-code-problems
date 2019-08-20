#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

//Initialize global variables

// create array with all the letters of alphabet a-z
char alphaArr[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

// Get single command-line argument (key)
int main(int argc, string argv[])
{
    // create a variable to hold the ciphertext
    char cipherText[] = "Mary had a little lamb.";
    int inputKey;
    //   check if not single char input
    if (argc != 2)
    {
        //print usage key error
        printf("Usage: ./caesar key\n");
        return 1;
    }
    //   if it is single char input
    if (argc == 2)
    {
        printf("Success\n");
        
        for (int i = 0; i < strlen(argv[1]); i++)
        {
            
            //check if input string are all digits
            if(isdigit(argv[1][i]) == 0) {
                //print usage key error
                printf("Usage: ./caesar key\n");
                return 1;
            }
            
        }
        // convert string to integer
            inputKey = atoi(argv[1]);
            //     print the input
            printf("Key is: %i\n", inputKey);
            
    }
    
    
    else {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    
    //Get user plaintext for cipher
    string plaintextMessage = get_string("Input message to be coded: ");
    //Print message
    printf("plaintext: %s\n", plaintextMessage);

    printf("%s\n", alphaArr);
    
    printf("%s\n", cipherText);
    
    
    
    return 0;
}
