class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        unique = set()
        mc = 0
        l, r = 0, 0

        while r < len(s):
            if s[r] in unique:
                mc = max(r - l, mc)
                while s[l] != s[r]:
                    unique.remove(s[l])
                    l += 1
                unique.remove(s[l])
                l += 1
            unique.add(s[r])
            r += 1
        mc = max(mc, r - l)
        return mc

