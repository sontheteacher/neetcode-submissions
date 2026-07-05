class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        /*
            for each word in list
                iterate the word + add to wildcard group
            create adjList
            iterate wildcards of beginWord
                for each wildcards, all words inside that group is neighbor
                add those words into bfs queue to construct adj list
        */

        if (endWord.empty() || beginWord.size() != endWord.size() || find(wordList.begin(), wordList.end(), endWord) == wordList.end())
            return 0;

        unordered_map<string, vector<string>> wildcard_groups;
        unordered_set<string> visited{beginWord};

        for (const auto& word : wordList) {
            string copy = word; // this creates a deep copy
            for (int i = 0; i < copy.size(); ++i) {
                copy[i] = '*';
                wildcard_groups[copy].push_back(word);
                copy[i] = word[i];
            }
        }

        queue<string> q;
        int level = 1;
        q.push(beginWord);
        while (!q.empty()) {
            int size = q.size();
            level++;
            for (int _ = 0; _ < size; _++) {
                const string curr = q.front(); q.pop();
                string copy = curr;
                for (int j = 0; j < curr.size(); ++j) {
                    copy[j] = '*';
                    for (const auto& word : wildcard_groups[copy]) {
                        if (word == endWord) return level;
                        if (visited.find(word) == visited.end()) {
                            q.push(word);
                            visited.insert(word);
                        }
                    }
                    wildcard_groups.erase(copy);
                    copy[j] = curr[j];
                }
            }
        }
        return 0;
    }
};
