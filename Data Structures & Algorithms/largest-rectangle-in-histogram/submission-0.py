class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        if len(heights) == 1:
            return heights[0]
        stack = [] # contains (index, height)
        res = 0

        for i, h in enumerate(heights):
            start = i
            while stack and stack[-1][1] > h: # stack not empty and last element height is greater than current heigh
                index, height = stack.pop()
                res = max(res, height * (i - index))
                start = index
            stack.append((start, h))
        
        for i, h in stack:
            res = max(res, (len(heights) - i) * h)
        return res
