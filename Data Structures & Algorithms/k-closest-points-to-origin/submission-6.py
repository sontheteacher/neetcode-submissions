import heapq

class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        d_x = lambda x: -(x[0]**2 + x[1]**2)
        heap = []
        heapq.heapify(heap)
        for x in points:
            heapq.heappush(heap, (d_x(x), x))
            if len(heap) > k:
                heapq.heappop(heap)
        return [x[1] for x in heap]