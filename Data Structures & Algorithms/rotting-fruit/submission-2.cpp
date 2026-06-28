class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<int>> directions = {
            {-1, 0}, {1, 0},
            {0, 1}, {0, -1}
        };

        int mins = 0;
        int fresh_ct = 0; // keep fresh count 
        queue<vector<int>> q;

        // first grab all the rottings as starting points
        for (int r = 0; r < grid.size(); ++r) {
            for (int c = 0; c < grid[0].size(); ++c) {
                if (grid[r][c] == 2) {
                    q.push({r, c});
                } else if (grid[r][c] == 1) {
                    ++fresh_ct;
                }
            }
        }

        while (!q.empty() && fresh_ct > 0) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                vector<int> top = q.front(); q.pop();
                int r = top[0], c = top[1];
                for (int i = 0; i < 4; ++i) {
                    int nr = r + directions[i][0];
                    int nc = c + directions[i][1];
                    if (nr >= 0 && nc >= 0 && nr < grid.size()
                        && nc < grid[0].size() && grid[nr][nc] == 1) {
                            grid[nr][nc] = 0;
                            --fresh_ct;
                            q.push({nr, nc});
                    }
                }
            }
            ++mins;
        }
        if (fresh_ct > 0) return -1;
        return mins;
    }
};
