// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// Choose number of buckets in hash table
const unsigned int N = 676; // first 2 letters including single letter words

// define pointer to word count variable
int word_count = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // take word and hash it using the has function to get a hash value
    int hash_value = hash(word);
    // create comparative pointer access linked list at that index
    node *temp_pointer = table[hash_value];
    // traverse the linked list looking for the word (strcasecmp)
    while (temp_pointer != NULL)
    {
        if (strcasecmp(word, temp_pointer->word) != 0)
        {
            temp_pointer = temp_pointer->next;
        }
        else
        {
            return true;
        }
    }
    return false;
}

// Hashes word to a number (sum of first 2 letters)
unsigned int hash(const char *word)
{
    unsigned int sum_word;

    if (word[1] == '\0')
    {
        sum_word = (toupper(word[0]) - 'A') * 26 + ('A' - 'A');
    }
    else
    {
        sum_word = (toupper(word[0]) - 'A') * 26 + (toupper(word[1]) - 'A');
    }
    sum_word = sum_word % N;

    return sum_word;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // open dictionary file
    FILE *dictionaryfile = fopen(dictionary, "r");
    // check to make sure it opens properly
    if (dictionaryfile == NULL)
    {
        printf("Could not open dictionaryfile.\n");
        return 1;
    }
    // variables
    char wordbuffer[LENGTH];
    int *word_count_location = &word_count;

    // read each word in the file
    while (fscanf(dictionaryfile, "%s", wordbuffer) != EOF)
    {
        // create a new node for each word
        node *new_node = malloc(sizeof(node));
        // make sure memory is there (check)
        if (new_node == NULL)
        {
            printf("Memory not allocated\n");
            return NULL;
        }
        // copy new word into the new node
        strcpy(new_node->word, wordbuffer);
        // hash the new word to get a hash value
        int hash_value = hash(new_node->word);
        // insert node into hash table at the hash value location
        new_node->next =
            table[hash_value];        // set new node pointer to start of linked list at hash value
        table[hash_value] = new_node; // set head of list pointer to the new node
        // count of how many new words are created - will feed into size
        (*word_count_location)++;
    }
    // close dictionary file
    fclose(dictionaryfile);
    return true; // return true if it works false if doesnt
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // call value stored in word_count- word_count_location is a pointer pointing to the variable
    // word count
    int *word_count_location = &word_count;
    return *word_count_location;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // for every index in the hash table
    for (int counter = 0; counter < N + 1; counter++)
    {
        // create 2 temp pointers to the head of that index
        node *temp_pointer_1 = table[counter];
        node *temp_pointer_2 = table[counter];
        // while loop to traverse over the list until next is NULL
        while (temp_pointer_1 != NULL)
        {
            // set one to the next pointer
            temp_pointer_1 = temp_pointer_1->next;
            // free current node
            free(temp_pointer_2);
            // reset pointer to equal first
            temp_pointer_2 = temp_pointer_1;
        }
    }
    return true;
}
