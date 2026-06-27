class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
       unordered_set<int> set;
       for (const int num : nums) {
        if (set.find(num) == set.end()) {
            set.insert(num);
        } else return true;
       }
       return false;
    }
};