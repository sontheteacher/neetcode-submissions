class Solution {
public:
    int characterReplacement(string s, int k) {
       int l = 0, res = 0;
       unordered_map<char, int> counter;
       int maxf = 0;

       for (int r = 0; r < s.size(); ++r) {
        counter[s[r]]++;
        maxf = max(maxf, counter[s[r]]);

        // expand and if invalid, then shrink
        while ((r - l + 1) - maxf > k) {
            counter[s[l]]--;
            l++;
        }
        res = max(r - l + 1, res);
       }
        return res;
    }
};
