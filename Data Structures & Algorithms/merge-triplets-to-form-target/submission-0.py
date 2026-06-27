class Solution:
    def merge(self, x, y):
        return [max(x[i], y[i]) for i in range(3)]
    def mergeTriplets(self, triplets: List[List[int]], target: List[int]) -> bool:
        res = triplets[0]
        for x in triplets:
            ml = self.merge(res, x)
            flag = True
            for i in range(3):
                if ml[i] > target[i]:
                    flag = False
                    break
            if flag: res = ml
        return res == target