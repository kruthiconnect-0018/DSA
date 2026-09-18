#include <stdlib.h>
#include <string.h>

void backtrack(char* current,
               int position,
               int open,
               int close,
               int n,
               char** result,
               int* returnSize)
{
    // A complete valid combination
    if (position == 2 * n)
    {
        current[position] = '\0';

        result[*returnSize] = malloc((2 * n + 1) * sizeof(char));
        strcpy(result[*returnSize], current);

        (*returnSize)++;
        return;
    }

    // Add '(' if we still have opening brackets available
    if (open < n)
    {
        current[position] = '(';

        backtrack(current,
                  position + 1,
                  open + 1,
                  close,
                  n,
                  result,
                  returnSize);
    }

    // Add ')' only if it won't make the sequence invalid
    if (close < open)
    {
        current[position] = ')';

        backtrack(current,
                  position + 1,
                  open,
                  close + 1,
                  n,
                  result,
                  returnSize);
    }
}

char** generateParenthesis(int n, int* returnSize)
{
    *returnSize = 0;

    // Maximum number of results for n <= 8 is 1430
    char** result = malloc(1430 * sizeof(char*));

    char* current = malloc((2 * n + 1) * sizeof(char));

    backtrack(current,
              0,
              0,
              0,
              n,
              result,
              returnSize);

    free(current);

    return result;
}