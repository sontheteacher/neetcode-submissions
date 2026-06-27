class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ROWS = grid.size(), COLS = grid[0].size();
        int fresh = 0;
        queue<pair<int, int>> q;

        for (int r = 0; r < ROWS; r ++) {
            for (int c = 0; c < COLS; c++) {
                if (grid[r][c] == 1) fresh ++;
                else if (grid[r][c] == 2) q.push({r, c});
            }
        }

        int time = 0;
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (fresh > 0 && !q.empty()) {
            int qLen = q.size();
            for (int i = 0; i < qLen; i++) {
                const auto curr = q.front();
                q.pop();
                int r = curr.first, c = curr.second;
                for (const auto& dir: directions) {
                    int row = r + dir.first;
                    int col = c + dir.second;
                    if (row >= 0 && row < ROWS && 
                        col >= 0 && col < COLS && grid[row][col] == 1) {
                            grid[row][col] = 2;
                            q.push({row, col});
                            fresh--;
                        }
                }
            }
            time++;
        }
        if (fresh) return -1;
        return time;
    }
};
