class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> adj;
        unordered_set<string> visited;
        for (auto ticket : tickets) {
            string src = ticket[0], dst = ticket[1];
            adj[src].push_back(dst);
        }
        for (auto& it : adj) {
            string key = it.first;
            // vector<string> neis = it.second; // this creates a copy
            // sort reverse lexicographically
            sort(it.second.begin(), it.second.end(), std::greater<string>());
        }
        stack<string> curr_path;
        vector<string> result;
        curr_path.push("JFK");

        while (curr_path.size() > 0) {
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
