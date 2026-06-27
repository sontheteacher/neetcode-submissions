class Solution:
    def rob(self, nums: List[int]) -> int:
        # rob 0 -> n -1 and 1 -> n
        if len(nums) == 1:
            return nums[0]
        if len(nums) == 2:
            return max(nums[0], nums[1])
        df1 = [nums[0], max(nums[0], nums[1])]
        df2 = [nums[1], max(nums[1], nums[2])]
        for i in range(len(nums) - 3):
            df1.append(max(df1[i + 1], nums[i + 2] + df1[i]))
            df2.append(max(df2[i + 1], nums[i + 3] + df2[i]))
        return max(df1[-1], df2[-1])