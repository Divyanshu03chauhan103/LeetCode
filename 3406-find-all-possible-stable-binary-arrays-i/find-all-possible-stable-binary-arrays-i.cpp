class Solution {
public:
    const int MOD = 1e9 + 7;
    int dp[201][201][2];

    int solve(int z, int o, int last, int limit) {
        if(z == 0 && o == 0) return 1;

        if(dp[z][o][last] != -1)
            return dp[z][o][last];

        long long ways = 0;

        if(last == 0) {
            for(int i = 1; i <= limit && i <= o; i++) {
                ways += solve(z, o - i, 1, limit);
                ways %= MOD;
            }
        }
        else {
            for(int i = 1; i <= limit && i <= z; i++) {
                ways += solve(z - i, o, 0, limit);
                ways %= MOD;
            }
        }

        return dp[z][o][last] = ways;
    }

    int numberOfStableArrays(int zero, int one, int limit) {

        memset(dp, -1, sizeof(dp));

        long long ans = 0;

        for(int i = 1; i <= limit && i <= zero; i++)
            ans = (ans + solve(zero - i, one, 0, limit)) % MOD;

        for(int i = 1; i <= limit && i <= one; i++)
            ans = (ans + solve(zero, one - i, 1, limit)) % MOD;

        return ans;
    }
};