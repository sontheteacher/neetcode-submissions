class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // logic, if curr subarray is negative
        // then we discard

        int maxSub = nums[0], currSub = 0;
        for (int num : nums) {
            currSub += num;
            maxSub = max(maxSub, currSub);
            if (currSub < 0) currSub = 0;
        }
        return maxSub;
    }
};
