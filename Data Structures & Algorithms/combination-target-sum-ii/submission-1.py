class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        
        candidates.sort()
        stack = []
        res = []
        def backtrack(st, s):
            if s == 0:
                res.append(stack.copy())
                return
            # if s < 0 or st == len(candidates):
            #     return
            
            if st < len(candidates) and candidates[st]:
                stack.append(candidates[st])
                backtrack(st + 1, s - candidates[st])
                stack.pop()
            else:
                return

            # stack.append(candidates[st])
            # backtrack(st + 1, s - candidates[st])
            # stack.pop()
            
            while st + 1 < len(candidates) and candidates[st] == candidates[st + 1]:
                st += 1
            backtrack(st + 1, s)
        backtrack(0, target)
        return res