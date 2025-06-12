class Solution {
public:
    int solve(int ind,int buy, vector<vector<int>>&dp,vector<int>&prices,int fee){

        if(ind==prices.size()) return 0;

        if(dp[ind][buy]!=-1) return dp[ind][buy];
        if(buy){

            return dp[ind][buy]=max(-prices[ind]+solve(ind+1,0,dp,prices,fee),solve(ind+1,1,dp,prices,fee));
        }
        else{
            return dp[ind][buy]=max(prices[ind]+solve(ind+1,1,dp,prices,fee)-fee,solve(ind+1,0,dp,prices,fee));
        }
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));

        return solve(0,1,dp,prices,fee);
    }
};