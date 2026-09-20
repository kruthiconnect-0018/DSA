#include <string.h>

int strStr(char* haystack, char* needle)
{
    int n = strlen(haystack);
    int m = strlen(needle);

    // Try every possible starting position
    for (int i = 0; i <= n - m; i++)
    {
        int j = 0;

        // Compare needle with haystack starting at i
        while (j < m && haystack[i + j] == needle[j])
        {
            j++;
        }

        // Entire needle matched
        if (j == m)
            return i;
    }

    return -1;
}