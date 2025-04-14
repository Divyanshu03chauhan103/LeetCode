class DisjointSet {
public:
    vector<int> parent, rank;

    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        iota(parent.begin(), parent.end(), 0); // initialize parent[i] = i
    }

    int find(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = find(parent[node]); // path compression
    }

    void unionByRank(int u, int v) {
        int pu = find(u);
        int pv = find(v);

        if (pu == pv) return;

        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else if (rank[pv] < rank[pu]) {
            parent[pv] = pu;
        } else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int maxRow = 0, maxCol = 0;
        for (auto& stone : stones) {
            maxRow = max(maxRow, stone[0]);
            maxCol = max(maxCol, stone[1]);
        }

        // Create DSU for (rows + cols + 1) to avoid overlap
        DisjointSet dsu(maxRow + maxCol + 2);

        unordered_set<int> uniqueNodes;

        for (auto& stone : stones) {
            int nodeRow = stone[0];
            int nodeCol = stone[1] + maxRow + 1; // shift column index to avoid clash with row index
            dsu.unionByRank(nodeRow, nodeCol);

            uniqueNodes.insert(nodeRow);
            uniqueNodes.insert(nodeCol);
        }

        int components = 0;
        for (int node : uniqueNodes) {
            if (dsu.find(node) == node) {
                components++;
            }
        }

        return stones.size() - components;
    }
};