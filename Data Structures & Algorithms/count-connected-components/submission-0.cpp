class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto edge : edges) {
            auto v1 = edge[0], v2 = edge[1];
            adj[v1].push_back(v2);
            adj[v2].push_back(v1);
        }

        unordered_set<int> visited;
        // keep track of nodes not visited, for purpose of cnt components
        for (int i = 0; i < n; ++i)
            visited.insert(i);

        int c = 0;
        while (!visited.empty()) {
            int head = *visited.begin();
            dfs(head, -1, adj, visited);
            ++c;
        }
        return c;
    }

private:
    void dfs(int node, int parent, const vector<vector<int>>& adj, unordered_set<int>& visit) {
        if (!visit.count(node)) // equivalent to visited
            return;
        visit.erase(node);

        for (int nei : adj[node]) {
            if (nei == parent)
                continue;
            dfs(nei, node, adj, visit);
        }
        return;
    }
};
