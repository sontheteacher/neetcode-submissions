class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        res = nums[0]
        curr = nums[0]
        for n in nums[1:]:
            curr = max(n, n + curr)
            res = max(curr, res)
        return res