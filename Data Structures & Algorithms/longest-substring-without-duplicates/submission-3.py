class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        unique = set()
        mc = 0
        l, r = 0, 0

        while r < len(s):
            while s[r] in unique:
                    unique.remove(s[l])
                    l += 1
            unique.add(s[r])
            r += 1
            mc = max(mc, r - l)
        return mc

