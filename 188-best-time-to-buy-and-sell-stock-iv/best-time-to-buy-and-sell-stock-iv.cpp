class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        
        int n=prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));
        
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                for(int K=1;K<=k;K++){
                     if(buy){

                         dp[ind][buy][K]=max(-prices[ind]+dp[ind+1][0][K],dp[ind+1][1][K]);
                    }else{
                         dp[ind][buy][K]=max(prices[ind]+dp[ind+1][1][K-1],dp[ind+1][0][K]);
                    }
                }
            }
        }
        return dp[0][1][k];
    }
};