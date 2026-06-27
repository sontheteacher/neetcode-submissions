class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> adj;
        for (auto ticket : tickets) {
            string src = ticket[0], dst = ticket[1];
            adj[src].push_back(dst);
        }
        for (const auto& pair: adj) {
            string key = pair.first;
            sort(adj[key].begin(), adj[key].end(), std::greater<string>());
        }

        stack<string> curr_path;
        vector<string> result;
        curr_path.push("JFK");
        while(!curr_path.empty()) {
                string curr = curr_path.top();
                if (adj[curr].size() > 0) {
                    string next = adj[curr].back();
                    adj[curr].pop_back();
                    curr_path.push(next);
                } else {
                    curr_path.pop();
                    result.push_back(curr);
                }
            }
        reverse(result.rbegin(), result.rend());
        return result;
    }
};