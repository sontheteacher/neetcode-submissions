class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        start, end = newInterval[0], newInterval[1]
        res = []
        
        for i in range(len(intervals)):
            if end < intervals[i][0]:
                res.append([start, end])
                return res + intervals[i:]
            elif start > intervals[i][1]:
                res.append(intervals[i])
            else:
                start = min(start, intervals[i][0])
                end = max(end, intervals[i][1])
        res.append([start, end])
        return res