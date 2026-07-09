class Solution {
public:
    int ROWS, COLS;
    const vector<vector<int>> DIRS{
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}
       };
    bool exist(vector<vector<char>>& board, string word) {

       // DFS/backtracking
       // mark visited cell with '#'
       // start dfs/bfs at every cell, match word by character
        ROWS = board.size();
        COLS = board[0].size();

        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                if (dfs(board, word, i, j, 0)) return true;
            }
        }

        return false;
    }

    bool dfs(vector<vector<char>>& board, string word, int r, int c, int i) {
        if (i == word.size()) return true;

        if (r < 0 || c < 0 || r >= ROWS || c >= COLS 
            || board[r][c] != word[i] || board[r][c] == '#')
            return false;

        board[r][c] = '#';
        bool res = false;
        for (int j = 0; j < 4; ++j) {
            res = res || dfs(board, word, r + DIRS[j][0], c + DIRS[j][1], i + 1);
        }
        board[r][c] = word[i]; // restore to backtrack
        return res;
    }
};
