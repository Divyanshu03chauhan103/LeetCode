class Solution {
public:
    int mod = 1e9+7;
    int m, n;

    // memo[i][j] = {maxProduct, minProduct}
    vector<vector<pair<long long, long long>>> memo;
    vector<vector<bool>> vis;

    pair<long long, long long> solve(int i, int j, vector<vector<int>>& grid) {

        // out of bounds
        if(i >= m || j >= n) return {LLONG_MIN, LLONG_MAX};

        // destination
        if(i == m-1 && j == n-1) {
            return {grid[i][j], grid[i][j]};
        }

        if(vis[i][j]) return memo[i][j];

        auto right = solve(i, j+1, grid);
        auto down  = solve(i+1, j, grid);

        long long val = grid[i][j];

        long long maxi = LLONG_MIN;
        long long mini = LLONG_MAX;

        // process right
        if(right.first != LLONG_MIN) {
            maxi = max(maxi, val * right.first);
            mini = min(mini, val * right.first);
        }
        if(right.second != LLONG_MAX) {
            maxi = max(maxi, val * right.second);
            mini = min(mini, val * right.second);
        }

        // process down
        if(down.first != LLONG_MIN) {
            maxi = max(maxi, val * down.first);
            mini = min(mini, val * down.first);
        }
        if(down.second != LLONG_MAX) {
            maxi = max(maxi, val * down.second);
            mini = min(mini, val * down.second);
        }

        vis[i][j] = true;
        return memo[i][j] = {maxi, mini};
    }

    int maxProductPath(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        memo.resize(m, vector<pair<long long,long long>>(n));
        vis.resize(m, vector<bool>(n, false));

        auto res = solve(0, 0, grid);

        long long maxProd = res.first;

        if(maxProd < 0) return -1;

        return maxProd % mod;
    }
};