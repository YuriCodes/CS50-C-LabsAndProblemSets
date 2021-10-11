// Implements a dictionary's functionality

#include <stdbool.h>
#include "dictionary.h"
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <strings.h>

unsigned int counter = 0;
// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 26;

//Unsigned int for positive hash value
unsigned int hash_value;
//Initialize hash value to word count
unsigned int word_count;

// Hash table
node *table[N];

// TODO
// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    //Hash word to obtain hash value
    int index = hash(word);
    //Access the linked list at that index in the hash table
    node *cursor_pointer = table[index];
    
    //Traverse linked list, looking for the word
    while (cursor_pointer != NULL)
    {
        //Compare strings case insensitive
        if (strcasecmp(cursor_pointer -> word, word) == 0)
        {
            return true;
        }
        //Move on ` to the next node
        cursor_pointer = cursor_pointer -> next;
    }
    return false;
}

// TODO
// Hashes word to a number
unsigned int hash(const char *word)
{
    unsigned int value = 0;
    unsigned int key_length = strlen(word);
    for (int i = 0; i < key_length; i++)
    {
        //For ascii value
        value = value + 37 * tolower(word[i]);
    }
    //For the return value not be greater than N 
    //For an appropiate range
    value = value % N;

    return value;
}

// TODO
// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
//Open dictionary for reading
    FILE *open_dictionary = fopen(dictionary, "r");
    //Error handling
    if (open_dictionary == NULL)
    {
        return false;
    }
    
    //Reading strings from dictionary file
    char dictionary_word[LENGTH + 1];
    
    //Read strings from dictionary
    //fscanf return EOF once it reaches the end of the file
    while (fscanf(open_dictionary, "%s", dictionary_word) != EOF)
    {
        //Create a new node for each word
        node *newNode = malloc(sizeof(node));
        //Error handling
        if (newNode == NULL)
        {
            return false;
        }
        
        //Copy strings into the new node
        strcpy(newNode -> word, dictionary_word);
        newNode -> next = NULL;
        
        //hash to optain hash value 
        int index = hash(dictionary_word);
        
        //check if the node is occupied then if not add the word to that index
        if (table[index] == NULL)
        {
            table[index] = newNode;
        }
        //Insert it in the location selected
        else 
        {
            newNode -> next = table[index];
            table[index] = newNode;
        }
        counter++;
    }
    //close it
    fclose(open_dictionary);
    return true;
}

// TODO
// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
   
    return counter;
}

// TODO
// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        while (table[i] != NULL)
        {
            //Let's keep track of which node we're at
            //move it to the next element before we free the first
            node *tmp = table[i] -> next;
            free(table[i]);
            table[i] = tmp;
        }
    }
    return true;
}
