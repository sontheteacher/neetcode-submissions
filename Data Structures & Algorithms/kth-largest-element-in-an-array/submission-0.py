import heapq

class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        
        x = nums[:k]
        heapq.heapify(x)
        for n in nums[k:]:
            if n > x[0]:
                heapq.heappushpop(x, n)
        return x[0]