class Solution:
    def increase(self, s, low, high):
            while low >= 0 and high < len(s) and s[low] == s[high]:
                low -= 1
                high += 1
            return low + 1, high - 1

    def longestPalindrome(self, s: str) -> str:
        if not s:
            return ""

        start, end = 0, 0
        for i in range(len(s)):
            low1, high1 = self.increase(s, i, i)
            low2, high2 = self.increase(s, i, i + 1)

            if high1 - low1 > end - start:
                start, end = low1, high1
            if high2 - low2 > end - start:
                start, end = low2, high2
        
        return s[start : end + 1]