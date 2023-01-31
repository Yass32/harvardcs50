// Implements a dictionary's functionality
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

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

/*Allocate memory for a new node
node *n = malloc(sizeof(node));*/

int words_count = 0; //To find the number of words in dictionary using load function

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *dict_file = fopen(dictionary, "r"); //Open dictionary file
    if (dict_file == NULL)
    {
        return false;
    }

    char word[LENGTH + 1];

    while (fscanf(dict_file, "%s", word) != EOF) //Read strings from file one at a time
    {
        node *new_node = malloc(sizeof(node)); //Create a new node for each word
        if (new_node == NULL)
        {
            return false;
        }
        strcpy(new_node->word, word);

        int hash_value = hash(word); //Hash word to obtain a hash value

        new_node->next = table[hash_value]; //Insert node into hash table at that location
        table[hash_value] = new_node;

        words_count++; //For size function
    }

    fclose(dict_file);
    return true;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    //return toupper(word[0]) - 'A';
    int value = strlen(word) % N; //Using hash function example3; Math using all letters
    if (value > N)
    {
        return value % N;
    }
    else
    {
        return value;
    }
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return words_count;
}

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int hash_value = hash(word); //Hash word to obtain a hash value

    node *cursor = table[hash_value]; //Access linked list at that index in the hash table

    while (cursor != NULL) //Traverse linked list, looking for the word
    {
        if(strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }
        else
        {
            cursor = cursor->next;
        }
    }
    return false;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 1; i <= N; i++)
    {
        if (table[i] != NULL)
        {
            node *cursor = table[i];
            while (cursor != NULL)
            {
                node *tmp = cursor;
                cursor = cursor->next;
                free(tmp);
            }
        }
        return true;

        /*while (cursor != NULL)
        {
            node *tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }

        if (tmp == NULL && cursor == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }*/
    }
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