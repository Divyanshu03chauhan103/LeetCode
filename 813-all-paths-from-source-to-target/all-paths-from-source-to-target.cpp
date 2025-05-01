class Solution {
public:
    void dfs(vector<vector<int>>& graph, vector<int>& visited, int source, int destination,
             vector<vector<int>>& result, vector<int>& curr) {
        if (source == destination) {
            result.push_back(curr);
            return;
        }

        visited[source] = 1;

        for (int i : graph[source]) {
            if (visited[i]) continue;
            curr.push_back(i);
            dfs(graph, visited, i, destination, result, curr);  
            curr.pop_back();  
        }

        visited[source] = 0; 
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n, 0);
        vector<vector<int>> result;
        vector<int> curr = {0};
        dfs(graph, visited, 0, n - 1, result, curr);
        return result;
    }
};
