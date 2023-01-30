// Implements a dictionary's functionality
#include <stdio.h>

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
    while (fread(buffer, sizeof(char), 1, dict_file)) //Read blocks of 512 bytes
    {
      //Check if bytes indicates that its a jpeg file
      if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
      {
          sprintf(file_name, "%03i.jpg", image_count);
          second_file = fopen(file_name, "w");
          image_count++;
      }
      if (second_file != NULL) //Check if output file is valid to write
      {
          fwrite(buffer, sizeof(char), 512, second_file);
      }
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