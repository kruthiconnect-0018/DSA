class Solution:
    def firstMissingPositive(self, nums):
        n = len(nums)

        # Put each number in its correct position
        for i in range(n):
            while 1 <= nums[i] <= n and nums[nums[i] - 1] != nums[i]:
                correct_index = nums[i] - 1
                nums[i], nums[correct_index] = nums[correct_index], nums[i]

        # Find the first position containing the wrong number
        for i in range(n):
            if nums[i] != i + 1:
                return i + 1

        # All numbers 1 to n are present
        return n + 1