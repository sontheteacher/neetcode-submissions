class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        while(len(nums) != 0):
            if nums.pop() in nums:
                return True
        return False