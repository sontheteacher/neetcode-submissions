class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        queue<int> starts;
        vector<int> res;
        for (auto x : prerequisites) {
            int dst = x[0], src = x[1];
            ++indegree[dst];
            adj[src].push_back(dst);
        }
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) {
                starts.push(i);
            }
        }
        while (!starts.empty()) {
            int curr = starts.front(); starts.pop();
            res.push_back(curr);
            for (int neigh : adj[curr]) {
                indegree[neigh] -= 1;
                if (indegree[neigh] == 0)
                    starts.push(neigh);
            }
        }
        if (res.size() != numCourses) {
            res.clear();
        }
        return res;
    }
};
