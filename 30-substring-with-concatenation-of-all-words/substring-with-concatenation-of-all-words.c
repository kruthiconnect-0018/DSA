#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 20011
#define MAX_WORD_LEN 31

typedef struct
{
    char word[MAX_WORD_LEN];
    int count;
    int used;
} Entry;


/* Hash function */
unsigned int hash(char *str)
{
    unsigned int h = 0;

    while (*str)
    {
        h = h * 31 + (unsigned char)*str;
        str++;
    }

    return h % TABLE_SIZE;
}


/* Get frequency of a word */
int getCount(Entry *table, char *word)
{
    unsigned int index = hash(word);

    while (table[index].used)
    {
        if (strcmp(table[index].word, word) == 0)
        {
            return table[index].count;
        }

        index = (index + 1) % TABLE_SIZE;
    }

    return 0;
}


/* Add frequency */
void addCount(Entry *table, char *word)
{
    unsigned int index = hash(word);

    while (table[index].used)
    {
        if (strcmp(table[index].word, word) == 0)
        {
            table[index].count++;
            return;
        }

        index = (index + 1) % TABLE_SIZE;
    }

    table[index].used = 1;
    strcpy(table[index].word, word);
    table[index].count = 1;
}


/* Set frequency */
void setCount(Entry *table, char *word, int count)
{
    unsigned int index = hash(word);

    while (table[index].used)
    {
        if (strcmp(table[index].word, word) == 0)
        {
            table[index].count = count;
            return;
        }

        index = (index + 1) % TABLE_SIZE;
    }
}


/* Main LeetCode function */
int* findSubstring(char* s, char** words, int wordsSize,
                   int* returnSize)
{
    *returnSize = 0;

    int sLen = strlen(s);
    int wordLen = strlen(words[0]);

    int totalLen = wordLen * wordsSize;

    if (totalLen > sLen)
    {
        return NULL;
    }

    /*
     * Result can never contain more than sLen
     * starting positions.
     */
    int *result = malloc(sLen * sizeof(int));

    /*
     * Frequency table for required words.
     */
    Entry *required =
        calloc(TABLE_SIZE, sizeof(Entry));

    for (int i = 0; i < wordsSize; i++)
    {
        addCount(required, words[i]);
    }


    /*
     * We try every possible alignment.
     *
     * If wordLen = 3:
     *
     * offset 0:
     * 0, 3, 6, 9, ...
     *
     * offset 1:
     * 1, 4, 7, 10, ...
     *
     * offset 2:
     * 2, 5, 8, 11, ...
     */
    for (int offset = 0; offset < wordLen; offset++)
    {
        int left = offset;
        int right = offset;
        int count = 0;

        /*
         * Frequency table for current window.
         */
        Entry *current =
            calloc(TABLE_SIZE, sizeof(Entry));


        while (right + wordLen <= sLen)
        {
            /*
             * Get the next word from s.
             */
            char word[MAX_WORD_LEN];

            strncpy(word,
                    s + right,
                    wordLen);

            word[wordLen] = '\0';

            right += wordLen;


            /*
             * Check whether this word is required.
             */
            int requiredCount =
                getCount(required, word);


            /*
             * Word is not in words.
             *
             * Reset the entire window.
             */
            if (requiredCount == 0)
            {
                left = right;
                count = 0;

                free(current);

                current =
                    calloc(TABLE_SIZE,
                           sizeof(Entry));

                continue;
            }


            /*
             * Add word to current window.
             */
            addCount(current, word);
            count++;


            /*
             * Too many copies of this word?
             *
             * Example:
             *
             * Required:
             * foo -> 1
             *
             * Current:
             * foo -> 2
             *
             * Move left until valid.
             */
            while (getCount(current, word)
                   > requiredCount)
            {
                char leftWord[MAX_WORD_LEN];

                strncpy(leftWord,
                        s + left,
                        wordLen);

                leftWord[wordLen] = '\0';

                left += wordLen;
                count--;

                int oldCount =
                    getCount(current, leftWord);

                setCount(current,
                         leftWord,
                         oldCount - 1);
            }


            /*
             * We have exactly the required
             * number of words.
             */
            if (count == wordsSize)
            {
                result[*returnSize] = left;
                (*returnSize)++;


                /*
                 * Move left by one word.
                 *
                 * This allows overlapping
                 * answers.
                 */
                char leftWord[MAX_WORD_LEN];

                strncpy(leftWord,
                        s + left,
                        wordLen);

                leftWord[wordLen] = '\0';

                left += wordLen;
                count--;

                int oldCount =
                    getCount(current, leftWord);

                setCount(current,
                         leftWord,
                         oldCount - 1);
            }
        }

        free(current);
    }

    free(required);

    return result;
}