class Solution:
    def lengthOfLongestSubstring(self, s):

        characters = set()

        left = 0
        maximum = 0

        for right in range(len(s)):

            while s[right] in characters:
                characters.remove(s[left])
                left += 1

            characters.add(s[right])

            window_length = right - left + 1

            maximum = max(maximum, window_length)

        return maximum