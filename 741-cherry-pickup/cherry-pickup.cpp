class Solution {
public:
    int n;
    int dp[51][51][51];

    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        memset(dp, -1, sizeof(dp));
        int res = dfs(0, 0, 0, grid);
        return max(0, res); 
    }

    int dfs(int r1, int c1, int r2, vector<vector<int>>& grid) {
        int c2 = r1 + c1 - r2;

        if (r1 >= n || c1 >= n || r2 >= n || c2 >= n ||
            grid[r1][c1] == -1 || grid[r2][c2] == -1)
            return INT_MIN;

        if (r1 == n - 1 && c1 == n - 1)
            return grid[r1][c1];

        if (dp[r1][c1][r2] != -1)
            return dp[r1][c1][r2];

        int ans = grid[r1][c1];
        if (r1 != r2 || c1 != c2)
            ans += grid[r2][c2];

        int temp = max({
            dfs(r1 + 1, c1, r2 + 1, grid),
            dfs(r1, c1 + 1, r2, grid),
            dfs(r1 + 1, c1, r2, grid),
            dfs(r1, c1 + 1, r2 + 1, grid)
        });

        ans += temp;
        return dp[r1][c1][r2] = ans;
    }
};
