#include <stdlib.h>
#include <string.h>

char* convert(char* s, int numRows) {
    int n = strlen(s);

    // If only one row or rows >= string length
    if (numRows == 1 || numRows >= n) {
        return s;
    }

    // Allocate memory for result
    char* result = (char*)malloc((n + 1) * sizeof(char));

    int index = 0;

    // Read each row
    for (int row = 0; row < numRows; row++) {

        // Jump between characters
        int cycle = 2 * (numRows - 1);

        for (int i = row; i < n; i += cycle) {

            // Add vertical character
            result[index++] = s[i];

            // Add diagonal character
            int diagonal = i + cycle - 2 * row;

            if (row != 0 &&
                row != numRows - 1 &&
                diagonal < n) {

                result[index++] = s[diagonal];
            }
        }
    }

    result[index] = '\0';

    return result;
}