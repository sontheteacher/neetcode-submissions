class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // adj[i] contains neighbor of wordList[i]
        unordered_map<string, vector<string>> adj;
        unordered_set<string> visited;
        unordered_map<string, int> level;
        wordList.push_back(beginWord);
        if (!count(wordList.begin(), wordList.end(), endWord)) return 0;
        for (const string word : wordList) {
            int m = word.size();
            for (int i = 0; i < m; ++i) {
                string copy = word;
                copy[i] = '*';
                adj[word].push_back(copy); // wild card copy generated is unique for each word
                adj[copy].push_back(word); // all word unique, so no wild card has 2 repeated words
            }
        }
        // now do bfs
        queue<string> q;
        q.push(beginWord);
        visited.insert(beginWord);
        level[beginWord] = 0;
        while(!q.empty()) {
            string curr = q.front(); q.pop();
            for (int i = 0; i < adj[curr].size(); ++i) {
                string nei = adj[curr][i];
                if (!visited.count(nei)) {
                    visited.insert(nei);
                    q.push(nei);
                    level[nei] = level[curr] + 1;
                }
                if (nei == endWord)
                    return level[endWord] / 2 + 1;
            }
        }
        return 0;
    }
};
