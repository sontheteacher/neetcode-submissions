class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        res = []
        stack = []

        def backtrack():
            if len(nums) == 0:
                res.append(stack.copy())
            for n in nums:
                ind = nums.index(n)
                nums.remove(n)
                stack.append(n)
                backtrack()
                nums.insert(ind, stack.pop())
            return
        backtrack()
        return res