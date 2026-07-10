class Solution {
public:
    string minWindow(string s, string t) {
       if (t == "") return "";
       if (s.size() < t.size()) return "";

       unordered_map<char, int> countT, window;
       for (char c : t) countT[c]++;

       pair<int, int> res = {-1, -1};
       int resLen = INT_MAX;
       int have = 0, need = countT.size(); 
       int l = 0;

       for (int r = 0; r < s.length(); ++r) {
            char c = s[r];
            window[c]++;

            if (countT.count(c) && window[c] == countT[c])
                have++; // == and not >= since it multi-count
            
            while (have == need) {
                if ((r - l + 1) < resLen) {
                    resLen = r - l + 1;
                    res = {l, r};
                }

                window[s[l]]--;
                if (countT.count(s[l]) && window[s[l]] < countT[s[l]])
                    have--;
                l++;
            }
       }
       return resLen == INT_MAX ? "" : s.substr(res.first, resLen);
    }
};
