#include <stdlib.h>
#include <string.h>

char* letters[] = {
    "",
    "",
    "abc",
    "def",
    "ghi",
    "jkl",
    "mno",
    "pqrs",
    "tuv",
    "wxyz"
};

void backtrack(char* digits, int index, char* current,
               char** result, int* returnSize)
{
    // If we have processed all digits
    if (digits[index] == '\0')
    {
        current[index] = '\0';

        result[*returnSize] = malloc((index + 1) * sizeof(char));
        strcpy(result[*returnSize], current);

        (*returnSize)++;
        return;
    }

    // Get letters corresponding to current digit
    char* possible = letters[digits[index] - '0'];

    for (int i = 0; possible[i] != '\0'; i++)
    {
        current[index] = possible[i];

        // Process the next digit
        backtrack(digits, index + 1, current, result, returnSize);
    }
}

char** letterCombinations(char* digits, int* returnSize)
{
    *returnSize = 0;

    int n = strlen(digits);

    // Maximum possible combinations = 4^4 = 256
    char** result = malloc(256 * sizeof(char*));

    char* current = malloc((n + 1) * sizeof(char));

    backtrack(digits, 0, current, result, returnSize);

    free(current);

    return result;
}