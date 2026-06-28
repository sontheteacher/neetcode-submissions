class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if (n == 0 || n == 1) return n;
        int l = 0, r = 1;
        int res = 1;
        unordered_set<char> curr_chars{s[l]};
        while (r < n) {
            if (curr_chars.count(s[r])) {
                while (l < r && curr_chars.count(s[r])) {
                    curr_chars.erase(s[l]);
                    ++l;
                }
            }
            curr_chars.insert(s[r]);
            res = max(res, static_cast<int>(curr_chars.size()));
            ++r;
        }
        return res;
    }
};
