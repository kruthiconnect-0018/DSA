class Solution:
    def isNumber(self, s):
        seen_digit = False
        seen_dot = False
        seen_exp = False
        digit_after_exp = True

        for i in range(len(s)):
            c = s[i]

            if c >= '0' and c <= '9':
                seen_digit = True

                if seen_exp:
                    digit_after_exp = True

            elif c == '+' or c == '-':
                if i > 0 and s[i - 1] != 'e' and s[i - 1] != 'E':
                    return False

            elif c == '.':
                if seen_dot or seen_exp:
                    return False

                seen_dot = True

            elif c == 'e' or c == 'E':
                if seen_exp or not seen_digit:
                    return False

                seen_exp = True
                digit_after_exp = False

            else:
                return False

        return seen_digit and digit_after_exp