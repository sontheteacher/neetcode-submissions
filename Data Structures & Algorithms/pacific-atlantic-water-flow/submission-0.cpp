class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        // bfs on pacific starts and atlantic starts
        // and you take the nodes than can do for both

        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        queue<pair<int, int>> q1, q2;

        // prepare the 2 queues
        // first add horizontally
        for (int i = 0; i < n; ++i) {
            q1.push({0, i});
            pacific[0][i] = 1;
            q2.push({m - 1, i});
            atlantic[m - 1][i] = 1;
        }
        for (int i = 1; i < m; ++i){
            q1.push({i, 0});
            pacific[i][0] = 1;
            q2.push({m - i - 1, n - 1});
            atlantic[m - i - 1][n - 1] = 1;
        }
        bfs(q1, heights, pacific);
        bfs(q2, heights, atlantic);

        vector<vector<int>> res;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (pacific[i][j] && atlantic[i][j])
                    res.push_back({i, j});
            }
        }
        return res;
    }

    void bfs(queue<pair<int, int>>& q, const vector<vector<int>> map,
    vector<vector<bool>>& traverse) {
        int m = map.size(), n = map[0].size();
        pair<int, int> DIRS[4] = {{-1, 0}, {1, 0}, 
            {0, 1}, {0, -1}};
        while (!q.empty()) {
            auto [r, c] = q.front(); q.pop();
            for (auto [dr, dc] : DIRS) {
                int nr = r + dr, nc = c + dc;
                if (nr >= 0 && nr < m && nc >= 0 && nc < n
                && map[nr][nc] >= map[r][c] && !traverse[nr][nc]) {
                    traverse[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
    }
};
