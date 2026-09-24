class Solution:
    def permute(self, nums):
        result = []

        def backtrack(current, used):
            # We used all numbers
            if len(current) == len(nums):
                result.append(current[:])
                return

            for i in range(len(nums)):

                # Skip number if already used
                if used[i]:
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