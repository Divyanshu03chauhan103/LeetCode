class Solution {
public:
    bool dfs(int source,int destination,vector<vector<int>>&graph,vector<int>&visited){
        if(source==destination) return true;
        visited[source]=1;

        for(int i:graph[source]){
            
            if(visited[i]) continue;

            if(dfs(i,destination,graph,visited)) return true;
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        vector<vector<int>>graph(n);

        for(auto i:edges){
            int v=i[0];
            int u=i[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        vector<int>visited(n,0);
        return dfs(source,destination,graph,visited);

    }
};