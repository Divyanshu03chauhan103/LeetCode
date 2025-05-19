class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();

        vector<int>dp(amount+1,0),curr(amount+1,0);

        for(int i=1;i<=amount;i++){
            if(i%coins[0]==0) dp[i]=i/coins[0];
            else dp[i]=1e9;
        }
        

        for(int i=1;i<n;i++){
            for(int target = 0;target<=amount;target++){
                int notTake = dp[target];
                int take=1e9;
                if(coins[i]<=target){
                    take = 1+curr[target-coins[i]];
                }
                curr[target]=min(take,notTake);
            }
            dp=curr;

        }
      
        return dp[amount]>=1e9? -1:dp[amount];
    }
};