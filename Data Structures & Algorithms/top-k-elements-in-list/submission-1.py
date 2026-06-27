import numpy as np

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        count = {}
        for num in nums:
            count[num] = count.get(num, 0) + 1
        value_based = [key for key, value in sorted(count.items(), key=lambda count: count[1], reverse = True)]
        return value_based[:k]