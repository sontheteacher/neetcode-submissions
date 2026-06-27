class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
       unordered_set<int> curr;
       for (int i = 0; i < nums.size(); ++i) {
        if (curr.count(nums[i])) {
            return true;
        } else {
            curr.insert(nums[i]);
        }
       } 
       return false;
    }
};