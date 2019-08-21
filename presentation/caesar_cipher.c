#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>


//Initialize global variables

// create array with all the letters of alphabet a-z
char alphaArr[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
//get length of the denomArr
int alphaArrLength = sizeof(alphaArr)/sizeof(alphaArr[0]);
char cipherText[] = {'s'};

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

    // start a loop through each character of the plaintext
    for (int i = 0; i < strlen(plaintextMessage); i++) 
    {
        
        //   start another loop through the alpha letters array
        for (int j = 0; j < alphaArrLength; j++)  
        {
            //     check if the current plaintext char i matches the current alpha letter j
            if(plaintextMessage[i] == alphaArr[j]) 
            {
                //       if they match save the paintext char's index as a variable
                
                 int sumOfMatchingIndices = j + inputKey;
                 printf("sum of indices = %i\n", sumOfMatchingIndices);
                //         check if the alpha char's index + key value is > 26
                if (sumOfMatchingIndices > 26) {
                    //           if it is greater 
                   
                    printf("alphaChar index + key val greater than 26\n");
                    //             subtract 27 from sum of alpha char index and key value (this is final cipher char index)
                    int cipherCharIndex = sumOfMatchingIndices - 26;
                    // add char to final cipher text string
                        //lookup cipher text char index in alpha arr
                        char cipherTextChar = alphaArr[cipherCharIndex];
                        printf("final cipher text char: %c\n", cipherTextChar);
                        //append the cipher text char to cipher text string
                        
                        //check if ciphertext is initialized as string and if so overwrite it with first letter
                        if (cipherText[0] != cipherTextChar) {
                            cipherText[0] = cipherTextChar;
                        }
                        else {
                            //cipherText[strlen(cipherText) + 1] = cipherTextChar;
                            strcat(cipherTextChar, cipherText);
                        }
                        
                }

                
                //printf("plaintext: %c matches alpha %c: \n", plaintextMessage[i], alphaArr[j]);
            }
            
            //printf("%c\n", alphaArr[j]);
        }
        
        
        //printf("%c\n", plaintextMessage[i]);
    }





//            if it is not greater
//              save char index + key value as cipher text index
//              check alpha array for character at cipher-text index
//                append character to cipherString var.
//         continue looping until it is found
//        repeat process for each character of plaintext
    
    
    // print plaintext: plainString
    // print ciphertext: cipherString//Print message
    printf("plaintext: %s\n", plaintextMessage);
    printf("ciphertext: %s\n", cipherText);
    
    
    
    return 0;
}
