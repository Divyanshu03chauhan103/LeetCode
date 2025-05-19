class Solution {
public:
    int solve(int i,int target,vector<vector<int>>&dp,vector<int>&coins){
        if(target==0) return 0;
        if(i==0){
            return target%coins[i]==0? target/coins[i]:1e9;
        }
        if(dp[i][target]!=-1) return dp[i][target];
        int notTake = solve(i-1,target,dp,coins);

        int take=1e9;
        if(coins[i]<=target){
            take = 1+solve(i,target-coins[i],dp,coins);
        }

        return dp[i][target]=min(take,notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();

        vector<vector<int>>dp(n,vector<int>(amount+1,-1));

        int result = solve(n-1,amount,dp,coins);

        if(result>=1e9) return -1;
        return result;
    }
};