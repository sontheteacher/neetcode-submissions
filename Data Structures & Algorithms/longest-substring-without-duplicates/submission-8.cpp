class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       int n = s.size();
       unordered_map<char, int> last_char;
       int l = 0;
       int res = 0;
       for (int r = 0; r < n; ++r) {
        if (last_char.count(s[r])) {
            l = max(last_char[s[r]] + 1, l);
        }
        last_char[s[r]] = r;
        res = max(res, r - l + 1);
       } 
       return res;
    }
};
