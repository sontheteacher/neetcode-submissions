import random
from collections import defaultdict

class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        def max_sequence_length(pairs, key, nums) -> int:
            count = 0
            if not pairs.get(key):
                return 0
            lower, upper = pairs[key]
            while pairs.get(lower) is not None:
                hold = lower
                lower = pairs[lower][0]
                del pairs[hold]
                count += 1
                nums.remove(hold)
            while pairs.get(upper) is not None:
                hold = upper
                upper = pairs[upper][1]
                del pairs[hold]
                count += 1
                nums.remove(hold)
            del pairs[key]
            return count + 1

        pair = {}
        for num in nums:
            pair[num] = (num - 1, num + 1)
        max_length = 0
        nums = list(set(nums))
        while len(pair) != 0:
            curr = random.choice(nums)
            max_length = max(max_length, max_sequence_length(pair, curr, nums))
        return max_length

