class DSU{
public:
    vector<int> parent;
    vector<int> rank;

    DSU(int n) {
        parent.resize(n);
        rank.assign(n, 0);

        for (int i = 0; i < n; ++i) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]); // path compression
        return parent[x];
    }

    bool unite(int a, int b) {
        int root_a = find(a);
        int root_b = find(b);

        if (root_a == root_b) return false;

        if (rank[root_a] > rank[root_b]) {
            parent[root_b] = root_a;
        } else if (rank[root_b] > rank[root_a]) {
            parent[root_a] = root_b;
        } else {
            parent[root_a] = root_b;
            rank[root_b]++;
        }

        return true;
    }

    bool connected(int a, int b) {
        return find(a) == find(b);
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
       // priority queue {distance, p1, p2}
       priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > pq; 

        // init the pq of edges
        for (int i = 0; i < points.size() - 1; ++i) {
            for (int j = i; j < points.size(); ++j) {
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];
                int dist = abs(x1 - x2) + abs(y1 - y2);
                pq.push({dist, i, j});
            }
        }

        int cost = 0;

        DSU dsu(points.size());
        while(!pq.empty()) {
            auto curr = pq.top(); pq.pop();
            int dist = curr[0];
            int p1 = curr[1], p2 = curr[2];
            if (dsu.unite(p1, p2)) cost += dist;
        }

        return cost;
    }
};
