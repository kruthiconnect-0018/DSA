#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool isValid(char* s)
{
    int n = strlen(s);

    char* stack = malloc(n * sizeof(char));
    int top = -1;

    for (int i = 0; i < n; i++)
    {
        char c = s[i];

        // Opening bracket
        if (c == '(' || c == '[' || c == '{')
        {
            stack[++top] = c;
        }
        else
        {
            // Stack is empty
            if (top == -1)
            {
                free(stack);
                return false;
            }

            // Get the top opening bracket
            char open = stack[top--];

            // Check whether brackets match
            if ((c == ')' && open != '(') ||
                (c == ']' && open != '[') ||
                (c == '}' && open != '{'))
            {
                free(stack);
                return false;
            }
        }
    }

    // Valid only if no opening brackets remain
    bool result = (top == -1);

    free(stack);

    return result;
}