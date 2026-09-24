class Solution:
    def isMatch(self, s, p):
        m = len(s)
        n = len(p)

        # dp[j] means whether the current part of s
        # matches p[:j]
        dp = [False] * (n + 1)

        # Empty string matches empty pattern
        dp[0] = True

        # Handle '*' matching an empty string
        for j in range(1, n + 1):
            if p[j - 1] == '*':
                dp[j] = dp[j - 1]
            else:
                break

        for i in range(1, m + 1):
            new_dp = [False] * (n + 1)

            for j in range(1, n + 1):

                if p[j - 1] == '*':
                    # '*' matches zero characters
                    # OR '*' matches one/more characters
                    new_dp[j] = new_dp[j - 1] or dp[j]

                elif p[j - 1] == '?' or p[j - 1] == s[i - 1]:
                    new_dp[j] = dp[j - 1]

            dp = new_dp

        return dp[n]