class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        numset = set(nums)
        length = 0
        for num in numset:
            if num - 1 not in numset:
                curr_length = 0
                while num in numset:
                    curr_length += 1
                    num = num + 1
                length = max(curr_length, length)
        return length

