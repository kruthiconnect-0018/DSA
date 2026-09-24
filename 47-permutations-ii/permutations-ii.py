class Solution:
    def permuteUnique(self, nums):
        result = []

        nums.sort()

        def backtrack(current, used):
            if len(current) == len(nums):
                result.append(current[:])
                return

            for i in range(len(nums)):

                # Already used in current permutation
                if used[i]:
                    continue

                # Skip duplicate at the same level
                if i > 0 and nums[i] == nums[i - 1] and not used[i - 1]:
                    continue

                # Choose
                used[i] = True
                current.append(nums[i])

                # Explore
                backtrack(current, used)

                # Undo
                current.pop()
                used[i] = False

        used = [False] * len(nums)

        backtrack([], used)

        return result