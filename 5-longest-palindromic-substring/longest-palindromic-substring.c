#include <string.h>
#include <stdlib.h>

char* longestPalindrome(char* s)
{
    int n = strlen(s);

    if (n < 2)
        return s;

    int start = 0;
    int maxLength = 1;

    for (int i = 0; i < n; i++)
    {
        // Odd-length palindrome
        int left = i;
        int right = i;

        while (left >= 0 && right < n && s[left] == s[right])
        {
            if (right - left + 1 > maxLength)
            {
                start = left;
                maxLength = right - left + 1;
            }

            left--;
            right++;
        }

        // Even-length palindrome
        left = i;
        right = i + 1;

        while (left >= 0 && right < n && s[left] == s[right])
        {
            if (right - left + 1 > maxLength)
            {
                start = left;
                maxLength = right - left + 1;
            }

            left--;
            right++;
        }
    }

    char* result = malloc((maxLength + 1) * sizeof(char));

    strncpy(result, s + start, maxLength);
    result[maxLength] = '\0';

    return result;
}