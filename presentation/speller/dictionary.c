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
            printf("New first node created. Word val: %s\n", hashtable[hashedWord]->word);
        }
            
        //else if other nodes exist
        else 
        {
            printf("nodes already exist");
            
             //allocate memory for new node
            node *newNode = malloc(sizeof(node)); 
            //assign node->word to word
            strcpy(newNode->word, word);
            //assign node->next of first node to point to new node
            strcpy(hashtable[hashedWord]->next, newNode->next);
            //assign new node->next to = first node in link list's next value
            strcpy(newNode->word, hashtable[hashedWord]->next);
            //print new node in hashtable word and print word it points to
            printf("first word: %s, second word: %s\n", hashtable[hashedWord]->word,  hashtable[hashedWord]->next->word);
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
    // TODO
    return 0;
}

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO
    return false;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    return false;
}
