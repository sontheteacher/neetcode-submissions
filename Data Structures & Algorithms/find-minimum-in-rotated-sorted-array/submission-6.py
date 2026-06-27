class Solution:
    def findMin(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]
        elif len(nums) == 2:
            return min(nums)
        l, r = 0, len(nums) - 1
        while l < r - 1:
            # Original list
            if nums[l] < nums[r]:
                return nums[l]
            mid = l + (r - l) // 2

            # Mid belong to the left segment
            if nums[mid] > nums[l]:
                l = mid
            elif nums[mid] < nums[r]:
                r = mid
        return nums[l + 1]