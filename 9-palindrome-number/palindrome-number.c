#include <stdbool.h>

bool isPalindrome(int x) {

    // Negative numbers are not palindromes
    if (x < 0) {
        return false;
    }

    // Numbers ending in 0 are not palindromes,
    // except 0 itself
    if (x != 0 && x % 10 == 0) {
        return false;
    }

    int reversed = 0;

    // Reverse only half of the number
    while (x > reversed) {
        int digit = x % 10;

        reversed = reversed * 10 + digit;

        x = x / 10;
    }

    // Even number of digits
    if (x == reversed) {
        return true;
    }

    // Odd number of digits
    // Ignore the middle digit
    if (x == reversed / 10) {
        return true;
    }

    return false;
}