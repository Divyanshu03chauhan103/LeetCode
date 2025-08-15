class Solution {
public:
    vector<int>parent;
    vector<int>rank;

    int find(int i,vector<int>&parent){
        if(i==parent[i]) return i;

        return parent[i]=find(parent[i],parent);
    }

    void Union(int a,int b){
        int parent_a=find(a,parent);
        int parent_b=find(b,parent);

        if(parent_a==parent_b) return ;

        if(rank[parent_a]>rank[parent_b]){
            parent[parent_b]=parent_a;
        }
        else if(rank[parent_b]>rank[parent_a]){
            parent[parent_a]=parent_b;
        }else{
            parent[parent_a]=parent_b;
            rank[parent_b]++;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        int edges=connections.size();
        if(edges < n - 1) return -1;

        for(auto i:connections){
            int u=i[0];
            int v=i[1];
            if(find(u,parent)!=find(v,parent)){
                Union(u,v);
                n--;
            }
        }
        return n-1;
    }
};