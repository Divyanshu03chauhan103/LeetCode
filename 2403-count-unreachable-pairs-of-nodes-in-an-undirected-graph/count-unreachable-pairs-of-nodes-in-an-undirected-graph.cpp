class Solution {
public:
    vector<int>parent;
    vector<int>rank;
    int find(int i,vector<int>&parent){
        if(i==parent[i]) return i;
        return parent[i]=find(parent[i],parent);
    }

    void Union(int u,int v){
        int u_parent=find(u,parent);
        int v_parent=find(v,parent);

        if(u_parent==v_parent) return;

        if(rank[u_parent]>rank[v_parent]){
            parent[v_parent]=u_parent;
        }else if(rank[v_parent]>rank[u_parent]){
            parent[u_parent]=v_parent;
        }else{
            parent[u_parent]=v_parent;
            rank[v_parent]++;
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }

        for(vector<int>a:edges){
            int u=a[0];
            int v=a[1];
            Union(u,v);
        }

        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[find(i,parent)]++;
        }

        long long result=0;
        long long remaningNodes=n;
        for(auto i=mp.begin();i!=mp.end();i++){
            int size=i->second;
            result+=size*(remaningNodes-size);
            remaningNodes=remaningNodes-size;
        }
        return result;
    }
};