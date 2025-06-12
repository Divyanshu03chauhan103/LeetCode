class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        
        int n=prices.size();
        vector<vector<int>>curr(2,vector<int>(k+1,0)),after(3,vector<int>(k+1,0));
        
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                for(int K=1;K<=k;K++){
                     if(buy){

                         curr[buy][K]=max(-prices[ind]+after[0][K],after[1][K]);
                    }else{
                         curr[buy][K]=max(prices[ind]+after[1][K-1],after[0][K]);
                    }
                }
                after=curr;
            }
        }
        return curr[1][k];
    }
};