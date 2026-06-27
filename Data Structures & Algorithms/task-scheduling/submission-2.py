from collections import Counter
from heapq import heapify, heappush, heappop

class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        c = Counter(tasks)
        heap = []
        for el in c:
            heap.append((-c[el], el))
        heapq.heapify(heap)
        
        time = 0
        while len(heap) > 0:
            cycle = []
            for i in range(n + 1):
                if len(heap) > 0:
                    f, e = heappop(heap)
                    cycle.append((f + 1, e))
                    time += 1
            flag = False
            for f, e in cycle:
                if f < 0:
                    flag = True
                    heappush(heap, (f, e))
            if flag:
                time += n + 1 - len(cycle)
        return time    
                