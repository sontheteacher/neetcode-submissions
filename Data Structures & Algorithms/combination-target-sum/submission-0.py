class Solution:
    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        s = []
        stack = []
        nums.sort()

        def backtrack(r, st):
            if r == 0:
                s.append(stack.copy())
                return
            for i in range(st, len(nums)):
                if r - nums[i] >= 0:
                    stack.append(nums[i])
                    backtrack(r - nums[i], i)
                    stack.pop()
                else:
                    break
            return
        
        backtrack(target, 0)
        return s