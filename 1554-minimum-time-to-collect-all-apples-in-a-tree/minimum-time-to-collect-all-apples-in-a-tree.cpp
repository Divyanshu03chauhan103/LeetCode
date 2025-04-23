class Solution {
public:
    int dfs(vector<vector<int>>& adj, vector<bool>& hasApple, int node,vector<bool>&visited) {
        int totalTime = 0;
        visited[node]=true;
        for (int child : adj[node]) {
            if(visited[child]) continue;
            int childTime = dfs(adj, hasApple, child,visited);
           
            if (childTime > 0 || hasApple[child]) {
                totalTime += childTime + 2;
            }
        }

        return totalTime;
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n);
        for (auto u : edges) {
            adj[u[0]].push_back(u[1]);
            adj[u[1]].push_back(u[0]);
        }
        vector<bool>visited(n,false);
        return dfs(adj, hasApple, 0,visited);
    }
};
