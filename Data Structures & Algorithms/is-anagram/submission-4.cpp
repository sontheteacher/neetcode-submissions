class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
       vector<int> count_a(26, 0);
       vector<int> count_b(26, 0);
       char a = 'a';
       for (int i = 0; i < s.size(); ++i) {
        count_a[s[i] - a] += 1;
        count_b[t[i] - a] += 1;
       }
       return count_a == count_b;
    }
};
