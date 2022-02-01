// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <strings.h>
#include <stdio.h>
#include <stdlib.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 10000;

// Hash table
node *table[N];

// Total word counter
int word_counter = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // Hash word to obtain a hash value
    int hashValue = hash(word);

    // Access linked list at that index in the hash table
    node *n = table[hashValue];
    while (n != NULL)
    {
        // Traverse linked list, looking for the word
        if (strcasecmp(n->word, word) == 0)
        {
            return true;
        }
        n = n->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // Hash function - sum of ASCII letters in word
    int sum = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        int hashIndex = toupper(word[i]) - 'A';
        sum += sum^(hashIndex + 1);
    }
    return sum % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Open dictionary file
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        printf("Invalid file.\n");
        return false;
    }

    // Read strings from file one at a time
    char word[LENGTH + 1];
    while (fscanf(file, "%s", word) != EOF)
    {
        // Create a new node for each word
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }

        // Copy word into node
        strcpy(n->word, word);
        n->next = NULL;
        word_counter++;

         // Hash word using hash function to obtain hash value
        int index = hash(word);

        // Insert node into hash table at that location given by hash function
        if (table[index] == NULL)
        {
            table[index] = n;
        }
        else
        {
            n->next = table[index];
            table[index] = n;
        }
    }
    printf("Dictionary loaded with %i words.\n", word_counter);
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return word_counter;
}

void freeNode(node *n)
{
    while (n != NULL)
    {
        node *nextNode = n->next;
        free(n);
        n = nextNode;
    }
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        freeNode(table[i]);
    }
    return true;
}