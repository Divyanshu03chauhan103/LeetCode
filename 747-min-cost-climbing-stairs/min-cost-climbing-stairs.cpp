class Solution {
public:
    int solve(vector<int>&cost,int index,vector<int>&dp){

        if(index>=cost.size()) return 0;
        if(dp[index]!=-1) return dp[index];
        int cost_one_step = cost[index]+solve(cost,index+1,dp);
        int cost_two_step = cost[index]+solve(cost,index+2,dp);

        return dp[index] = min(cost_one_step,cost_two_step);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>dp(cost.size(),-1);
        int result= min(solve(cost,0,dp),solve(cost,1,dp));

        return result;
    }
};