class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n + 1, INT_MAX);
        vector<vector<pair<int, int> >> adj(n + 1);
        dist[k] = 0;
        for (const vector<int> edge : times) {
            // edges are {target, weight}
            adj[edge[0]].push_back({edge[1], edge[2]});
        }

        priority_queue<pair<int, int>> q;
        q.push({dist[k], k}); // contains {dist[v], v}
        while (!q.empty()) {
            int curr = q.top().second; q.pop();
            for (auto [nei, w] : adj[curr]) {
                if (dist[curr] + w < dist[nei]) {
                    dist[nei] = dist[curr] + w;
                    q.push({dist[nei], nei});
                }
            }
        }
        int maxie = *max_element(dist.begin() + 1, dist.end());
        if (maxie < INT_MAX)
            return maxie;
        return -1;
    }
};
