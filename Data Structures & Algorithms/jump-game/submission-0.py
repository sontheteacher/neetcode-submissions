class Solution:
    def jump(self, nums: List[int]) -> bool:
        # Check whether I can jump from beginning to end of list
        if len(nums) == 1:
            return True
        elif nums[0] == 0:
            return False
        else:
            for i in range(nums[0]):
                if self.jump(nums[i + 1::]):
                    return True
            return False

    def canJump(self, nums: List[int]) -> bool:
        return self.jump(nums)
    
        