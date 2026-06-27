class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       map<int, int> mp;
       int res = 0;
       for (const auto& num : nums) {
            if (mp[num]) continue;
            mp[num] = mp[num - 1] + mp[num + 1] + 1;
            mp[num - mp[num - 1]] = mp[num];
            mp[num + mp[num + 1]] = mp[num];
            res = max(res, mp[num]);
       } 
       return res;
    }
};
