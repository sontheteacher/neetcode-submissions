class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        dif = []
        for i in range(len(nums)):
            if nums[i] in dif:
                return [dif.index(nums[i]), i]
            else:
                dif.append(target - nums[i])