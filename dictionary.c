#include <stdbool.h>
#include <ctype.h>
#include <stdio.h>
#include <cs50.h>
#include <strings.h>
#include <string.h>
#include <stdlib.h>

#include "dictionary.h"

typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

node *head = NULL;
node *hashtable[1000];
int hashtable_size = 1000;
int wordcount;

int hash_function(const char *key)
{
    int index = 0;

    for (int i = 0; key[i] != '\0'; i++)
    {
        index += toupper(key[i]);
    }

    return index % hashtable_size;
}

bool check(const char *word)
{
    int hash = hash_function(word);

    if (hashtable[hash] == NULL)
    {
        return false;
    }

    else if (hashtable[hash] != NULL)
    {
        node *cursor = hashtable[hash];
        while (cursor != NULL)
        {
            int i;
            i = strcasecmp(cursor->word, word);
            if (i == 0)
            {
                return true;
            }
            else
            {
                cursor = cursor->next;
            }
        }
    }
    return false;
}

bool load(const char *dictionary)
{
    FILE *fp = fopen(dictionary, "r");
    if (fp == NULL)
    {
        return false;
    }
    char word[LENGTH + 1];
    wordcount = 0;

    while (fscanf(fp, "%s", word) != EOF)
    {
        node *new_node = malloc(sizeof(node));
        memset(new_node, 0, sizeof(node));

        if (new_node == NULL)
        {
            unload();
            return false;
        }
        wordcount++;

        strcpy(new_node->word, word);

        int hashed = hash_function(word);

        if (hashtable[hashed] == NULL)
        {
            hashtable[hashed] = new_node;
            head = new_node;
        }
        else
        {
            new_node->next = hashtable[hashed];
            hashtable[hashed] = new_node;
            head = new_node;
        }
    }

    fclose(fp);
    return true;
}

unsigned int size(void)
{
    return wordcount;;
}

bool unload(void)
{
    for (int i = 0; i < hashtable_size; i++)
    {
        if (hashtable[i] != NULL)
        {
            node *cursor = hashtable[i];
            while (cursor != NULL)
            {
                node *temp = cursor;
                cursor = cursor->next;
                free(temp);

            }
        }
    }
    return true;

}