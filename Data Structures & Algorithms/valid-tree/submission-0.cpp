class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> visited(n, false);
        for (vector<int> edge : edges) {
            int v1 = edge[0], v2 = edge[1];
            adj[v1].push_back(v2);
            adj[v2].push_back(v1);
        }

        if (!dfs(0, -1, adj, visited))
            return false;
        return count(visited.begin(), visited.end(), true) == n;
    }


private:
    bool dfs(int node, int parent, const vector<vector<int>>& adj, vector<bool>& visited) {
        if (visited[node])
            return false;
        
        visited[node] = true;
        for (int nei : adj[node]) {
            if (nei == parent)
                continue;
            if (!dfs(nei, node, adj, visited))
                return false;
        }

        return true;
    }
};
