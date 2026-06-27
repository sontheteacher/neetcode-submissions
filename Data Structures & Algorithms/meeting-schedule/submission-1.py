"""
Definition of Interval:
class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end
"""

class Solution:
    def canAttendMeetings(self, intervals: List[Interval]) -> bool:
        if len(intervals) <= 1:
            return True
        intervals.sort(key = lambda x: (x.start, x.end))
        pe = intervals[0].end
        for i in intervals[1:]:
            s, e = i.start, i.end
            if s < pe:
                return False
            pe = e
        return True