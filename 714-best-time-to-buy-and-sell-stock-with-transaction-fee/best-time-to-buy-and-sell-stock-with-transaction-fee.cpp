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
        vector<int>curr(2,0),after(2,0);

        for(int ind=n-1;ind>=0;ind--){

            for(int buy=0;buy<=1;buy++){

                if(buy){

                   curr[buy]=max(-prices[ind]+after[0],after[1]);
                }
                else{
                    curr[buy]=max(prices[ind]+after[1]-fee,after[0]);
                }
            }
            after=curr;
        }
        return curr[1];
    }
};