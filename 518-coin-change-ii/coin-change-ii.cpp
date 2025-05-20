class Solution {
public:
    int change(int amount, vector<int>& coins) {
        const int MOD = 1e10 + 7;
        int n = coins.size();
        vector<vector<long long int>> dp(n, vector<long long int>(amount + 1, 0));

        for (int i = 0; i < n; i++) {
            dp[i][0] = 1;
        }

        for (int i = 0; i <= amount; i++) {
            if (i % coins[0] == 0) dp[0][i] = 1;
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= amount; j++) {
                long long int notTake = dp[i - 1][j];
                long long int take = 0;
                if (coins[i] <= j) {
                    take = dp[i][j - coins[i]];
                }
                dp[i][j] = (take + notTake) % MOD;
            }
        }

        return (int)dp[n - 1][amount];
    }
};
