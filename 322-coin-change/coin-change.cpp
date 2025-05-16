class Solution {
public:
    int solve(int i, int amount, vector<int>& coins, vector<vector<int>>& dp) {
        if (amount == 0) return 0;
        if (i >= coins.size()) return INT_MAX - 1;

        if (dp[i][amount] != -1) return dp[i][amount];

        int notTake = solve(i + 1, amount, coins, dp);
        int take = INT_MAX;
        if (coins[i] <= amount) {
            take = 1 + solve(i, amount - coins[i], coins, dp);
        }

        return dp[i][amount] = min(take, notTake);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));

        int res = solve(0, amount, coins, dp);
        return res >= INT_MAX - 1 ? -1 : res;
    }
};
