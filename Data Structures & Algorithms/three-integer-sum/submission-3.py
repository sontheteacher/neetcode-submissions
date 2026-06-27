class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        output = set()
        nums.sort()
        print(nums)
        for i in range(len(nums) - 2):
            left, right = i + 1, len(nums) - 1
            target = -nums[i]
            while left < right:
                s = nums[left] + nums[right]
                if s == target:
                    output.add((nums[left], nums[right]))
                    left += 1
                elif s > target:
                    right -= 1
                else:
                    left += 1
        out = []
        for t in output:
            out.append([t[0], t[1], -(t[0] + t[1])])
        return out
                        
        return output
            