class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        tank, st = 0, 0

        lefts = [gas[i] - cost[i] for i in range(len(gas))]
        if sum(lefts) < 0:
            return -1
        
        for i in range(len(gas)):
            left = lefts[i]
            if tank + left < 0:
                tank = 0
                st = i + 1
            else:
                tank += left
        return st