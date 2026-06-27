class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        zero_f_1 = False
        prod_excl_0 = 1
        for num in nums:
            if num == 0:
                if not zero_f_1:
                    zero_f_1 = True
                else:
                    return [0] * len(nums)
            else:
                prod_excl_0 *= num
        
        ans = [0]* len(nums)
        if zero_f_1:
            ans[nums.index(0)] = prod_excl_0
        else:
            for i in range(len(nums)):
                ans[i] = prod_excl_0 // nums[i]
        return ans

