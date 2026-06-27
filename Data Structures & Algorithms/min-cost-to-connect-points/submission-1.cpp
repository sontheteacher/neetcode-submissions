class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int total_cost = 0;
        int n = points.size();
        unordered_set<int> visit;
        priority_queue<pair<int, int>, 
            vector<pair<int, int>>, 
            greater<pair<int, int>> > queue; 
        vector<vector<pair<int, int>>> adj(n);
        // Setup adj list
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];
                int cost = abs(x1 - x2) + abs(y1 - y2);
                adj[i].push_back({j, cost});
                adj[j].push_back({i, cost});
            }
        }
        queue.push({0, 0}); // {weight, index}
        while (visit.size() < n) {
            auto [cost, id] = queue.top();
            queue.pop();
            if (visit.count(id))
                continue;
            visit.insert(id);
            total_cost += cost;
            for (auto [nei, w] : adj[id]) {
                queue.push({w, nei});
            }
        }
        return total_cost;
    }
};
