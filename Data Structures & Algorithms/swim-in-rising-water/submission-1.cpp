class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
            vector<int> const DIRS[4] = {
                {1, 0}, {-1, 0}, {0, 1}, {0, -1}
            };
            int N = grid.size();
            priority_queue< vector<int>, 
                vector<vector<int>>, greater<> > minHeap;
            set<pair<int, int>> visit;
            minHeap.push({grid[0][0], 0, 0});
            while (!minHeap.empty()) {
                auto curr =  minHeap.top(); minHeap.pop();
                int w = curr[0], r = curr[1], c = curr[2];
                if (visit.count({r, c}))
                    continue;
                visit.insert({r, c}); 
                if (r == N - 1 && c == N - 1) {
                    return w;
                }
                // else add each neighbor to minHeap
                for (auto dir : DIRS) {
                    int dr = dir[0], dc = dir[1];
                    int nr = r + dr, nc = c + dc;
                    if (nr >= 0 && nr < N && nc >= 0 && nc < N && !visit.count({nr, nc})) {
                        minHeap.push({max(w, grid[nr][nc]), nr, nc});
                    }
                }
            }
            return N * N;
    }
};
