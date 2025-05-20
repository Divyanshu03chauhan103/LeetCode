class Solution {
public:
    int change(int amount, vector<int>& coins) {
        const int MOD = 1e10 + 7;
        int n = coins.size();
        vector<long long int> prev(amount + 1, 0),curr(amount+1,0);

        
            prev[0] = 1;
        

        for (int i = 0; i <= amount; i++) {
            if (i % coins[0] == 0) prev[i] = 1;
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= amount; j++) {
                long long int notTake = prev[j];
                long long int take = 0;
                if (coins[i] <= j) {
                    take = curr[j - coins[i]];
                }
                curr[j] = (take + notTake) % MOD;
            }
            prev=curr;
        }

        return (int)prev[amount];
    }
};
