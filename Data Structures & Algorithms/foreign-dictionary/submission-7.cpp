class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char, int> indegree;
        
        // initialize so all characters are in the 2 maps
        for (string w : words) {
            for (char c : w) {
                adj[c] = unordered_set<char>();
                indegree[c] = 0;
            }
        }

        for (int i = 0; i < words.size() - 1; ++i) {
            string a = words[i], b = words[i + 1];
            int s = min(a.size(), b.size());

            if (a.size() > b.size() && 
                a.substr(0, s) == b.substr(0, s)) {
                    return "";
                }

            for (int j = 0; j < s; ++j) {
                if (a[j] != b[j]) {
                    if (!adj[a[j]].count(b[j])) {
                        adj[a[j]].insert(b[j]);
                        indegree[b[j]]++;
                    }
                    break;
                }
            }
        }

        queue<char> start;
        for (const auto& pair : indegree) {
            if (!pair.second)
                start.push(pair.first);
        }
        string res = "";
        while (!start.empty()) {
            char c = start.front(); start.pop();
            res = res + c;
            for (char n : adj[c]) {
                --indegree[n];
                if (!indegree[n]) // if indegree[n] is 0
                    start.push(n);
            }
        }
        
        return res.size() == indegree.size() ? res : "";
    }
};
