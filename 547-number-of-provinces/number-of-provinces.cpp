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
        vector<int> adj[n];  // Use 0-based indexing

        // Convert adjacency matrix to adjacency list
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && isConnected[i][j]) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int count = 0;
        vector<int> visited(n, 0); // Use correct size

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                count++;
                dfs(visited, adj, i);
            }
        }

        return count;
    }
};
