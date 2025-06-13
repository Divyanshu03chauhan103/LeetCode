class Solution {
public:
    int lengthOfLIS(vector<int>& nums){
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+2,0));
        
        for(int ind=n-1;ind>=0;ind--){
            for(int lastIndex=ind;lastIndex>=-1;lastIndex--){
                 int len=dp[ind+1][lastIndex+1];

                if(lastIndex==-1||nums[ind]>nums[lastIndex])
                    len=max(len,1+dp[ind+1][ind+1]);

                 dp[ind][lastIndex+1]=len;
            }
        }
        return dp[0][0];
    }
};