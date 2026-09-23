class Solution:
    def combinationSum2(self, candidates, target):
        result = []

        candidates.sort()

        def backtrack(start, remaining, current):

            if remaining == 0:
                result.append(current[:])
                return

            if remaining < 0:
                return

            for i in range(start, len(candidates)):

                # Skip duplicate combinations
                if i > start and candidates[i] == candidates[i - 1]:
                    continue

                # Since array is sorted
                if candidates[i] > remaining:
                    break

                # Choose
                current.append(candidates[i])

                # Move to i + 1 because each element can be used once
                backtrack(i + 1,
                          remaining - candidates[i],
                          current)

                # Undo
                current.pop()

        backtrack(0, target, [])

        return result