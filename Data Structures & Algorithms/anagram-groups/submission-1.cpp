class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> tracker;
        for (string word : strs) {
           vector<int> count(26, 0);
           for (char c : word) {
            count[c - 'a']++;
           } 
           string k = "";
           for (int c : count)
            k += to_string(c) + ','; 
            tracker[k].push_back(word);
        }
        vector<vector<string>> res;
        for (const auto& v : tracker)
            res.push_back(v.second);
        return res;
    }
};
