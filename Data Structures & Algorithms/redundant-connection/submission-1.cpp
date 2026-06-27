class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1);
        vector<int> rank(n + 1, 0);
        for (int i = 1; i < n + 1; ++i) 
            parent[i] = i; // initialize for union find
        
        for (const auto& edge : edges) {
            if (!Union(parent, rank, edge[0], edge[1]))
                return edge;
        }
        return {};
    }

private:
// find with path compression
    int Find(vector<int>& par, int n) {
        int p = par[n];
        if (p != par[p]) {
            // assign par[p] to its parent recursively and return that
            return par[p] = Find(par, p);
        }
        return p;
    }

// union by rank
    bool Union(vector<int>& par, vector<int>& rank, int n1, int n2) {
        int p1 = Find(par, n1);
        int p2 = Find(par, n2);
        if (p1 == p2) return false; // if same set -> redundant edge create cycle
        if (rank[p1] == rank[p2]) {
            ++rank[p1];
            par[p2] = p1;
        } else if (rank[p1] > rank[p2]) {
            par[p2] = p1;
        } else 
            par[p1] = p2;
        return true;
    }
};
