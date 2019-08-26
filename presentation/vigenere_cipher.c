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
//Initialize keyword
char inputKeyword;
int shiftedKey;

// Function declarations
int shiftKey(char c);

// Get single command-line argument (Keyword)
int main(int argc, string argv[])
{
    // create variable to hold user cipher Keyword
    
   

    //   check if not single word input
    if (argc != 2)
    {
        //print usage Keyword error
        printf("Usage: ./vigenere Keyword\n");
        return 1;
    }
    //   if it is single char input
    if (argc == 2)
    {
        //loop through all letters in the input string
        for (int i = 0; i < strlen(argv[1]); i++)
        {
            
            //check if input string letters are not alpha chars
            if(isalpha(argv[1][i]) == 0) {
                //if not print usage Keyword error
                printf("Usage: ./vigenere Keyword\n");
                return 1;
            }
            
        }
        // convert string to integer
            inputKeyword = *argv[1];
            
            //     print the input
            printf("Keyword is: %c\n", inputKeyword);
            shiftedKey = shiftKey(inputKeyword);
            printf("shifted key index: %i\n", shiftedKey);
            
    }
    
    
    else {
        printf("Usage: ./vigenere Keyword\n");
        return 1;
    }
    

    


    //Get user plaintext for cipher
    // string plaintextMessage = get_string("Input message to be coded: ");
    // //Create string size to match plaintext size
    // int plainMessageSize = strlen(plaintextMessage);
    // // //Allocate pointer to message size 
    // cipherText = (char *) malloc(plainMessageSize * 2);

    // // start a loop through each character of the plaintext
    // for (int i = 0; i < strlen(plaintextMessage); i++) 
    // {
    //     //Initialize variables:
    //     int cipherCharIndex;
    //     int sumOfMatchingIndices;
    //     char cipherTextChar;
    //     //   start another loop through the alpha letters array
    //     for (int j = 0; j < alphaArrLength; j++)  
    //     {
                //     check if the current plaintext char i matches the current alpha letter j
                //if(plaintextMessage[i] == alphaArr[j] || tolower(plaintextMessage[i]) == alphaArr[j]) 
                //{
    //             //       if they match save the paintext char's index as a variable
                
    //              sumOfMatchingIndices = j + inputKeyword;

    //              //check if index is 26
    //             if (sumOfMatchingIndices == 26)
    //             {
    //                 //  save char index + Keyword value as cipher text index
    //                 cipherCharIndex = sumOfMatchingIndices;
    //                 //check if character is uppercase
    //                 if(isupper(plaintextMessage[i])) {
    //                     //check alpha array for character at index
    //                         //save uppercase version as a variable
    //                     cipherTextChar = toupper(alphaArr[0]);
    //                     //append the cipher text char to cipher text string
    //                     cipherText[strlen(cipherText)] = cipherTextChar;
    //                 }
    //                 else {
    //                     //lookin alpha array for matching index and save
    //                     cipherTextChar = alphaArr[0];
    //                     //append the cipher text char to cipher text string
    //                     cipherText[strlen(cipherText)] = cipherTextChar;
    //                 }
                    
    //             }
    //             //   Perform decoding based on calculation
    //             else {
    //                 //calculation for cipher text character index
    //                 sumOfMatchingIndices = (j + inputKeyword) % 26;
                    
    //                 cipherCharIndex = sumOfMatchingIndices;
    //                 // add char to final cipher text string
    //                     //check if char is uppercase
    //                     if(isupper(plaintextMessage[i])) {
    //                         //lookup cipher text char index in alpha arr
    //                         cipherTextChar = toupper(alphaArr[cipherCharIndex]);
    //                         //append the cipher text char to cipher text string
    //                         cipherText[strlen(cipherText)] = cipherTextChar;
    //                         //strcat(cipherTextChar, cipherText);
    //                     }
    //                     else {
    //                         //lookup cipher text char index in alpha arr
    //                         cipherTextChar = alphaArr[cipherCharIndex];
    //                         //append the cipher text char to cipher text string
    //                         cipherText[strlen(cipherText)] = cipherTextChar;
    //                         //strcat(cipherTextChar, cipherText);
    //                     }
                            
    //             }
                
    //         }
    //         //         continue looping until it is found
         
         //}
        //      //else add the non-alpha character itself to the ciphertext
    //     if (isalpha(plaintextMessage[i]) == 0)
    //     {
    //         char plainTextNonAlphaChar = plaintextMessage[i];
    //         cipherText[strlen(cipherText)] = plainTextNonAlphaChar;

    //     }
    //     //repeat process for each character of plaintext
        
    // }


    
    
    // // // print plaintext: plainString
    // // // print ciphertext: cipherString//Print message
    // printf("plaintext: %s\n", plaintextMessage);
    // printf("ciphertext: %s\n", cipherText);
    
    
    
    return 0;
}

//Functions
int shiftKey(char c)
{
    int key;
    //calculate cipher index of c
    
    for (int j = 0; j < alphaArrLength; j++) {
        if (c == alphaArr[j]) {
            key = j;
        }
    }
    
// TODO
    return key;
}