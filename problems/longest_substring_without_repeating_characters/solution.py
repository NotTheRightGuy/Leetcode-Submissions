class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        distinct_char = set()
        l = 0
        res = 0
        for r in range(len(s)):
            while s[r] in distinct_char:
                distinct_char.remove(s[l])
                l += 1
            distinct_char.add(s[r])
            res = max(res,r-l+1)
        return res
        