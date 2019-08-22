#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>


//Initialize global variables

// create array with all the letters of alphabet a-z
char alphaArr[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
//get length of the denomArr
int alphaArrLength = sizeof(alphaArr)/sizeof(alphaArr[0]);
//Initialize pointer to hold dynamic length string
char *cipherText;


// Get single command-line argument (key)
int main(int argc, string argv[])
{
    // create variables to hold the ciphertext and user messages
    
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
    //Create string size to match plaintext size
    int plainMessageSize = strlen(plaintextMessage) + 10;
    //Allocate pointer to message size 
    cipherText = (char *) malloc(plainMessageSize);

    // start a loop through each character of the plaintext
    for (int i = 0; i < strlen(plaintextMessage); i++) 
    {
        //Initialize variables:
        int cipherCharIndex;
        int sumOfMatchingIndices;
        char cipherTextChar;
        //   start another loop through the alpha letters array
        for (int j = 0; j < alphaArrLength; j++)  
        {
            //     check if the current plaintext char i matches the current alpha letter j
            if(plaintextMessage[i] == alphaArr[j] || tolower(plaintextMessage[i]) == alphaArr[j]) 
            {
                //       if they match save the paintext char's index as a variable
                
                 sumOfMatchingIndices = j + inputKey;
                 printf("sum of indices = %i\n", sumOfMatchingIndices);
                //         check if the alpha char's index + key value is > 26
                if (sumOfMatchingIndices > 26) {
                    //           if it is greater 
                   
                    printf("alphaChar index + key val greater than 26\n");
                    //subtract amount over 26 from sum of alpha char index and key value (this is final cipher char index)
                    cipherCharIndex = sumOfMatchingIndices - 26;
                    // add char to final cipher text string
                        //check if char is uppercase
                        if(isupper(plaintextMessage[i])) {
                            //lookup cipher text char index in alpha arr
                            cipherTextChar = toupper(alphaArr[cipherCharIndex]);
                            printf("final cipher text char: %c\n", cipherTextChar);
                            //append the cipher text char to cipher text string
                        
                            cipherText[strlen(cipherText)] = cipherTextChar;
                            //strcat(cipherTextChar, cipherText);
                        }
                        else {
                            //lookup cipher text char index in alpha arr
                            cipherTextChar = alphaArr[cipherCharIndex];
                            printf("final cipher text char: %c\n", cipherTextChar);
                            //append the cipher text char to cipher text string
                        
                            cipherText[strlen(cipherText)] = cipherTextChar;
                            //strcat(cipherTextChar, cipherText);
                        }
                        
                        
                        
                }
                //if it is not greater
                else if (sumOfMatchingIndices <= 26)
                {
                    //              save char index + key value as cipher text index
                    cipherCharIndex = sumOfMatchingIndices;
                    //check if character is uppercase
                    if(isupper(plaintextMessage[i])) {
                        //              check alpha array for character at index
                            //save uppercase version as a variable
                        cipherTextChar = toupper(alphaArr[cipherCharIndex]);
                        //append the cipher text char to cipher text string
                        cipherText[strlen(cipherText)] = cipherTextChar;
                    }
                    else {
                        //lookin alpha array for matching index and save
                        cipherTextChar = alphaArr[cipherCharIndex];
                        //append the cipher text char to cipher text string
                        cipherText[strlen(cipherText)] = cipherTextChar;
                    }
                    
                }

                
                //printf("plaintext: %c matches alpha %c: \n", plaintextMessage[i], alphaArr[j]);
            }
            //         continue looping until it is found
            
           
            //printf("%c\n", alphaArr[j]);
        }
         //else add the character itself to the ciphertext
        if (isalpha(plaintextMessage[i]) == 0)
        {
            char plainTextNonAlphaChar = plaintextMessage[i];
            printf("plaintext char: %c\n", plainTextNonAlphaChar);
            cipherText[strlen(cipherText)] = plainTextNonAlphaChar;

        }
        //repeat process for each character of plaintext
        //printf("%c\n", plaintextMessage[i]);
    }


    
    
    // print plaintext: plainString
    // print ciphertext: cipherString//Print message
    printf("plaintext: %s\n", plaintextMessage);
    printf("ciphertext: %s\n", cipherText);
    
    
    
    return 0;
}
