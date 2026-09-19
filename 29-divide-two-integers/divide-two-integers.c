#include <limits.h>

int divide(int dividend, int divisor)
{
    // Special overflow case
    if (dividend == INT_MIN && divisor == -1)
        return INT_MAX;

    // Determine whether answer should be negative
    int negative = (dividend < 0) ^ (divisor < 0);

    // Use long long to safely handle INT_MIN
    long long a = dividend;
    long long b = divisor;

    if (a < 0)
        a = -a;

    if (b < 0)
        b = -b;

    long long quotient = 0;

    while (a >= b)
    {
        long long current = b;
        long long multiple = 1;

        // Find the largest doubled divisor <= dividend
        while (a >= (current << 1))
        {
            current <<= 1;
            multiple <<= 1;
        }

        a -= current;
        quotient += multiple;
    }

    if (negative)
        quotient = -quotient;

    // Clamp to 32-bit range
    if (quotient > INT_MAX)
        return INT_MAX;

    if (quotient < INT_MIN)
        return INT_MIN;

    return (int)quotient;
}