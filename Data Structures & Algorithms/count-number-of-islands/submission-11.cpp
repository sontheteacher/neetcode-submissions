class DSU {
public:
    vector<int> parent;
    vector<int> rank;

    DSU(int n) {
        parent.resize(n);
        rank.assign(n, 0); // init to 0

        for (int i = 0; i < n; ++i) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x) {
            // path compression
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    bool unite(int a, int b) {
        int root_a = find(a);
        int root_b = find(b);

        if (root_a == root_b) return false; // alr connected

        if (rank[root_a] < rank[root_b]) {
            parent[root_a] = root_b;
        } else if (rank[root_a] > rank[root_b]) {
            parent[root_b] = root_a;
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
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> dirs = {
            {1,0}, {-1,0}, {0,1}, {0,-1}
        };

        DSU dsu(rows * cols);
        int count = 0;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == '1') count++;
            }
        }

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == '0') continue;

                int id1 = r * cols + c;

                for (auto& d : dirs) {
                    int nr = r + d[0];
                    int nc = c + d[1];

                    if (nr < 0 || nc < 0 || nr >= rows || nc >= cols
                        || grid[nr][nc] == '0')
                        continue;

                    int id2 = nr * cols + nc;
                    if (dsu.unite(id1, id2)) count--;
                }
            }
        }

        return count;
    }
};
