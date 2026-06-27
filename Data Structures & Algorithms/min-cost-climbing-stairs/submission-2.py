class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        mc = [0, 0]
        for i in range(2, len(cost) + 1):
            mc.append(min(cost[i - 1] + mc[i - 1], cost[i - 2] + mc[i - 2]))
        return mc[-1]