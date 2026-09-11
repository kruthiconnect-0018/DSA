#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

double findMedianSortedArrays(int* nums1, int nums1Size,
                              int* nums2, int nums2Size)
{
    int total = nums1Size + nums2Size;

    int *nums = malloc(total * sizeof(int));

    // Copy nums1
    for (int i = 0; i < nums1Size; i++)
    {
        nums[i] = nums1[i];
    }

    // Copy nums2
    for (int i = 0; i < nums2Size; i++)
    {
        nums[nums1Size + i] = nums2[i];
    }

    // Sort the combined array
    qsort(nums, total, sizeof(int), compare);

    double median;

    if (total % 2 == 1)
    {
        // Odd number of elements
        median = nums[total / 2];
    }
    else
    {
        // Even number of elements
        int left = nums[total / 2 - 1];
        int right = nums[total / 2];

        median = (left + right) / 2.0;
    }

    free(nums);

    return median;
}