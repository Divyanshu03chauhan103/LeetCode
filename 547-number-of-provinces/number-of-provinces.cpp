class Solution {
public:
    void dfs(vector<vector<int>>&adj,vector<int>&visited,int &src){
        visited[src]=1;
        for(int i:adj[src]){
            if(!visited[i])
                dfs(adj,visited,i);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int v= isConnected.size();
        vector<vector<int>>adj(v+1,vector<int>(v+1));
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){

                if(isConnected[i][j]){
                    int u=i+1;
                    int V=j+1;
                    adj[u].push_back(V);
                    adj[V].push_back(u);
                }
            }
        }

        vector<int>visited(v+1,0);
        int result=0;
        for(int i=1;i<=v;i++){
            if(!visited[i]){
                dfs(adj,visited,i);
                result++;
            }
        }
        return result;
    }
};