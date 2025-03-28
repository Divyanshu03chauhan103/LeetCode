class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        
        // Add all boundary cells that are 1s to the queue.
        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 1) {
                q.push({i, 0});
                grid[i][0] = 0; // mark as visited
            }
            if (grid[i][m-1] == 1) {
                q.push({i, m-1});
                grid[i][m-1] = 0;
            }
        }
        for (int j = 0; j < m; j++) {
            if (grid[0][j] == 1) {
                q.push({0, j});
                grid[0][j] = 0;
            }
            if (grid[n-1][j] == 1) {
                q.push({n-1, j});
                grid[n-1][j] = 0;
            }
        }
        
        int Drow[] = {0, +1, 0, -1};
        int Dcol[] = {+1, 0, -1, 0};
        
        // Multi-source BFS
        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int new_row = row + Drow[i];
                int new_col = col + Dcol[i];
                if (new_row >= 0 && new_row < n && new_col >= 0 && new_col < m && grid[new_row][new_col] == 1) {
                    q.push({new_row, new_col});
                    grid[new_row][new_col] = 0; // mark as visited
                }
            }
        }
        
        // Count remaining 1s
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1)
                    count++;
            }
        }
        return count;
    }
};
