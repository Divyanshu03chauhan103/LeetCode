class Solution {
public:
    void dfs(vector<int>& visited, vector<int> adj[], int node) {
        visited[node] = 1;
        for (auto i : adj[node]) {
            if (!visited[i])
                dfs(visited, adj, i);
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adj[n+1]; 

       
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && isConnected[i][j]) {
                    adj[i+1].push_back(j+1);
                    adj[j+1].push_back(i+1);
                }
            }
        }

        int count = 0;
        vector<int> visited(n+1, 0); 

        for (int i = 1; i < n+1; i++) {
            if (!visited[i]) {
                count++;
                dfs(visited, adj, i);
            }
        }

        return count;
    }
};
