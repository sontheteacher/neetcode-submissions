class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // bubble sort
       for (int i = 0; i < nums.size(); ++i) {
        for (int j = 0; j + 1 < nums.size() - i; ++j) {
            if (nums[j] > nums[j + 1]) swap(nums[j], nums[j + 1]);
        }
       } 
       return nums;
    }
};