class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        l = 0
        res = 0
        count = {}
        maxf = 0
        for r, item in enumerate(s):
            count[item] = 1 + count.get(item, 0)
            maxf = max(count[item], maxf)

            while (r - l + 1) - maxf > k:
                count[s[l]] -= 1
                l += 1
            res = max(res, r - l + 1)
    
        return res