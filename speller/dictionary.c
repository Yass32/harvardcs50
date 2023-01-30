// Implements a dictionary's functionality
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <ctype.h>
#include <stdbool.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

//Allocate memory for a new node
node *new_node = malloc(sizeof(node));

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *dict_file = fopen(dictionary, "r"); //Open file

    if (dict_file == NULL) //Check if file is valid to read
    {
      return false;
    }

    char buffer[LENGTH + 1];
    /*while (fread(buffer, sizeof(char), 1, dict_file)) //Read each lines of the dictionary
    {
    }*/

    while (fscanf(dict_file, "%s", buffer) != 0)
    {
        //node *word_node = malloc(sizeof(node));

        strcpy(word_node->word, buffer);
        word_node->next = table[hash(buffer)];
        table[hash(buffer)] = word_node;
    }

    fclose(dict_file);
    return true;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    return false;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}



/*
unsigned int hash(const char *word)
{
    unsigned int hash = 0;
    for (int i = 0, n = strlen(word); i < n; i++)
        hash = (hash << 2) ^ word[i];
    return hash % HASHTABLE_SIZE;
}

bool load(const char *dictionary)
{
    // Initialize hash table
    for (int i = 0; i < HASHTABLE_SIZE; i++)
        hashtable[i] = NULL;

    // Open dictionary
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
        return false;

    // Buffer for a word
    char word[LENGTH + 1];

    // Insert words into hash table
    while (fscanf(file, "%s", word) != EOF)
    {
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
            return false;

        strcpy(new_node->word, word);
        new_node->next = hashtable[hash(word)];
        hashtable[hash(word)] = new_node;
    }

    // Close dictionary
    fclose(file);

    // Indicate success
    return true;
}

bool check(const char *word)
{
    node *cursor = hashtable[hash(word)];
    while (cursor != NULL)
    {
        if (strcasecmp(cursor->word, word) == 0)
            return true;
        cursor = cursor->next;
    }
    return false;
}

unsigned int size(void)
{
    unsigned int count = 0;
    for (int i = 0; i < HASHTABLE_SIZE; i++)
    {
        node *cursor = hashtable[i];
        while (cursor != NULL)
        {
            count++;
            cursor = cursor->next;
        }
    }
    return count;
}
*/