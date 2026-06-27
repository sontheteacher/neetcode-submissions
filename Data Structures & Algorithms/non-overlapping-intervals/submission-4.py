class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort(key= lambda x: (x[1], x[0]))
        count = 0
        i = 1
        s = len(intervals)
        while i < len(intervals):
            if intervals[i][0] < intervals[i - 1][1]:
                intervals.pop(i)
                i -= 1
                count += 1
            i += 1
        print(intervals)
        return count