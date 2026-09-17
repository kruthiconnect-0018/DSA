#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int threeSumClosest(int* nums, int numsSize, int target)
{
    // Sort the array
    qsort(nums, numsSize, sizeof(int), compare);

    // Start with the first possible 3-number sum
    int closest = nums[0] + nums[1] + nums[2];

    for (int i = 0; i < numsSize - 2; i++)
    {
        int left = i + 1;
        int right = numsSize - 1;

        while (left < right)
        {
            int sum = nums[i] + nums[left] + nums[right];

            // Exact match
            if (sum == target)
                return sum;

            // Check whether this sum is closer
            if (abs(sum - target) < abs(closest - target))
            {
                closest = sum;
            }

            // Move the appropriate pointer
            if (sum < target)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
    }

    return closest;
}