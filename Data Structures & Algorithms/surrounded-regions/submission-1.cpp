class Solution {
public:
    void solve(vector<vector<char>>& board) {
        // BFS from the 'O's on the edges, those are the ones untouched
        queue<pair<int, int>> q;
        int n = board.size(), m = board[0].size();
        for (int i = 0; i < n; ++i) {
            if (board[i][0] == 'O'){
                q.push({i, 0});
                board[i][0] = 'T';
            }
            if (board[i][m - 1] == 'O') {
                q.push({i, m - 1});
                board[i][m - 1] = 'T';
            }
        }
        for (int i = 1; i < m - 1; ++i) {
            if (board[0][i] == 'O'){
                q.push({0, i});
                board[0][i] = 'T';
            }
            if (board[n - 1][i] == 'O'){
                q.push({n - 1, i});
                board[n - 1][i] = 'T';
            }
        }



        // BFS
        const pair<int, int> DIRS[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while (!q.empty()) {
            auto [r, c] = q.front(); q.pop();
            for (auto [dr, dc] : DIRS) {
                int nr = r + dr, nc = c + dc;
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && board[nr][nc] == 'O'){
                    board[nr][nc] = 'T';
                    q.push({nr, nc});
                }
            }
        }

        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < m; ++c) {
                if (board[r][c] == 'T') {
                    board[r][c] = 'O';
                } else if (board[r][c] == 'O') {
                    board[r][c] = 'X';
                }
            }
        }
        return;
    }
};
