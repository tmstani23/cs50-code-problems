// Implements a dictionary's functionality
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "dictionary.h"

// Represents number of buckets in a hash table
#define N 26

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Represents a hash table
node *hashtable[N];
// Count for number of words loaded in dictionary
int wordsInDict = 0;

// Hashes word to a number between 0 and 25, inclusive, based on its first letter
unsigned int hash(const char *word)
{
    return tolower(word[0]) - 'a';
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // Initialize hash table
    for (int i = 0; i < N; i++)
    {
        hashtable[i] = NULL;
    }

    // Open dictionary
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        unload();
        return false;
    }

    // Buffer for a word
    char word[LENGTH + 1];

    // Insert words into hash table
    while (fscanf(file, "%s", word) != EOF)
    {
        
        //check dictionary word
        printf("word in in dict: %s\n", word);
        //hash word into number
        unsigned int hashedWord = hash(word);
        printf("hashed word index: %u\n", hashedWord);
        
        //copy node into hashtable at hashedWord location
        //if there aren't any nodes in linked list yet
        if(hashtable[hashedWord] == NULL) 
        {
            //allocate memory for new node
            node *newNode = malloc(sizeof(node));
            //assign node->word to word
            strcpy(newNode->word, word);
            //assign node->next null
            newNode->next = NULL;
            //copy new node into hash table at hashedWord location
            hashtable[hashedWord] = newNode;
            //update word count
            wordsInDict++;
            printf("New first node created. Word val: %s\n", hashtable[hashedWord]->word);
        }
        else if (hashtable[hashedWord]->next == NULL) 
        {
            //allocate memory for new node
            node *newNode = malloc(sizeof(node));
            //assign word into new node
            strcpy(newNode->word, word);
            //assign first node's next pointer to point to new node
            hashtable[hashedWord]->next = newNode;
            //assign new nodes pointer to NULL
            newNode->next = NULL;
            //update word count
            wordsInDict++;
            
        }    
        //else 2 other nodes exist
        else 
        {
            printf("nodes already exist");
            
             //allocate memory for new node
            node *newNode = malloc(sizeof(node)); 
            //assign node->word to word
            strcpy(newNode->word, word);
            
            //assign new node's next pointer point to where head node is currently pointing
            newNode->next = hashtable[hashedWord]->next;
            //assign first node's next pointer to point to new node
            hashtable[hashedWord]->next = newNode;
            //update word count
            wordsInDict++;
            //print new node in hashtable word and print word it points to
            printf("new word node added: %s\n", word);
        }
           
            
        

    }

    // Close dictionary
    fclose(file);

    // Indicate success
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return wordsInDict;
}

char *lowercaseString(char* inputWord) {
   
    int i = 0;

    while(inputWord[i]) {
      inputWord[i] = tolower(inputWord[i]);
      i++;
   }
   
   //printf("inputword: %s\n", inputWord);
   return inputWord;
}

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    node *cursor = hashtable[hash(word)];
    char wordSize[LENGTH + 1];
    char *dictWord = malloc(sizeof(wordSize));
    char *textWord = malloc(sizeof(wordSize));
    
    // //loop through linked list at hashed index
    while (cursor != NULL)
    {  
        strcpy(dictWord, cursor->word);
        strcpy(textWord, word);
    
        dictWord = lowercaseString(dictWord);
        textWord = lowercaseString(textWord);
        
        
       //check if word in dictionary is the same as the text word
        if (strcmp(dictWord, textWord) == 0) 
        {
            //printf("\nmatch found for dict word: %s\n", dictWord);
            return true;
        }
        cursor = cursor->next;
    }
    //free mallocs
    free(dictWord);
    free(textWord);

    return false;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    //loop through entire hashtable array
    for (int i = 0; i < N; i++)
    {
        //if head value isn't NULL
        if (hashtable[i] != NULL) 
        {
            node *cursor = hashtable[i];
            //loop through link list
            while(cursor != NULL)
            {
                //set temp cursor pointer
                node *tmpCursor = cursor;
                //advance cursor
                cursor = cursor->next;
                //free temp cursor
                //check tmp cursor state before free
                free(tmpCursor);
                //zet pntr to null for free verification
                tmpCursor = NULL;
                //return false to the function if the cursor wasn't freed
                if(tmpCursor != NULL) 
                {
                    return false;
                }
                
            }
            
        }
        //else continue the loop
    }   
    //return true once loop finishes
    return true;
}
