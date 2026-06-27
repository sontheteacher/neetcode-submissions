class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        heap = nums[0:k]
        heapq.heapify(heap)

        for n in nums[k:]:
            if n > heap[0]:
                heapq.heappushpop(heap, n)
        return heap[0]
        