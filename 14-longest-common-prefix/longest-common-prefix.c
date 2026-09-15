#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize)
{
    // Start with the first string as the prefix
    char* prefix = strs[0];

    for (int i = 1; i < strsSize; i++)
    {
        int j = 0;

        // Compare prefix with current string
        while (prefix[j] != '\0' &&
               strs[i][j] != '\0' &&
               prefix[j] == strs[i][j])
        {
            j++;
        }

        // End the prefix at the first mismatch
        prefix[j] = '\0';

        // No common prefix
        if (prefix[0] == '\0')
            return prefix;
    }

    return prefix;
}