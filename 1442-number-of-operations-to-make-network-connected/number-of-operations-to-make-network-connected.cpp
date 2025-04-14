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
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        Disjoint Ds(n);
        int extra=0;
        for(auto i:connections){
            int u=i[0];
            int v=i[1];

            if(Ds.find(u)==Ds.find(v))
                extra++;
            else{
                Ds.unionbyrank(u,v);
            }
            
        }

        int components=0;
        for(int i=0;i<n;i++){
            if(Ds.find(i)==i) components++;
           
        }

        if(components-1>extra) return -1;

        return components-1;
    }
};