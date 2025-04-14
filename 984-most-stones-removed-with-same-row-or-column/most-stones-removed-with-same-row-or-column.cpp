class Disjoint{
    vector<int>parent,rank;

    public:
        Disjoint(int n){
            parent.resize(n+1,0);
            rank.resize(n+1,0);

            for(int i=0;i<n+1;i++){
                parent[i]=i;
            }
        }

        int find(int node){
            if(node==parent[node]) return node;

            return parent[node]=find(parent[node]);
        }

        void unionbyrank(int v,int u){
            int ult_u=find(u);
            int ult_v=find(v);

            if(rank[ult_u]>rank[ult_v]){
                parent[ult_v]=ult_u;
            }
            else if(rank[ult_u]<rank[ult_v])
                parent[ult_u]=ult_v;
            else{
                parent[ult_u]=ult_v;
                rank[ult_v]++;
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
        Disjoint dsu(maxRow + maxCol + 2);

        unordered_set<int> uniqueNodes;

        for (auto& stone : stones) {
            int nodeRow = stone[0];
            int nodeCol = stone[1] + maxRow + 1; // shift column index to avoid clash with row index
            dsu.unionbyrank(nodeRow, nodeCol);

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