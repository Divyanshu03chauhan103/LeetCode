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
        
        int row=0;
        int col=0;

        for(auto i:stones){
            row=max(row,i[0]);
            col=max(col,i[1]);
        }


        Disjoint Ds(row+col+2);
        unordered_set<int>st;

        for(auto i:stones){
            int node_row=i[0];
            int node_col=row+1+i[1];

            Ds.unionbyrank(node_row,node_col);
            st.insert(node_row);
            st.insert(node_col);
        }


        int count=0;

        for(auto i:st){
            if(Ds.find(i)==i) count++;
        }

        return stones.size()-count;
    }
};