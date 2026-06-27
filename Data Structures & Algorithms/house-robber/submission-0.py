class Solution:
    def rob(self, nums: List[int]) -> int:
        max_rob = [nums[0], max(nums[:2])]
        for i in range(2, len(nums)):
            max_rob.append(max(nums[i] + max_rob[i - 2], max_rob[i - 1]))
        return max_rob[-1]