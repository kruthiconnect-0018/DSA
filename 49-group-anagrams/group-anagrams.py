class Solution:
    def groupAnagrams(self, strs):
        groups = {}

        for word in strs:
            # Count frequency of each character
            count = [0] * 26

            for char in word:
                index = ord(char) - ord('a')
                count[index] += 1

            # Convert list to tuple so it can be used as a dictionary key
            key = tuple(count)

            if key not in groups:
                groups[key] = []

            groups[key].append(word)

        return list(groups.values())