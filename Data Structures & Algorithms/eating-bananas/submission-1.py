from math import ceil

class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        def calc_h(k, piles):
            s = 0
            for banana in piles:
                s += ceil(banana / k)
            return s

        # Binary search on all values of k
        l, r = 1, max(piles)
        min_k = r
        while l <= r:
            m = l + (r - l) // 2
            mh = calc_h(m, piles)
            if mh <= h:
                r = m - 1
                min_k = m
            else:
                l = m + 1
        return min_k


