class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,-1);

        for(int i=0;i<n;i++){
            if(color[i]==-1 && !dfs(graph,color,1,i)){
                return false;
            }
        }
        return true;
    }

    bool dfs(vector<vector<int>>&adj,vector<int>&color,int curr_color,int src){
        color[src]=curr_color;

        for(int i:adj[src]){
            if(color[src]==color[i]) return false;
            if(color[i]==-1 && !dfs(adj,color,1 - curr_color,i)) return false;
        }
        return true;
    }
};