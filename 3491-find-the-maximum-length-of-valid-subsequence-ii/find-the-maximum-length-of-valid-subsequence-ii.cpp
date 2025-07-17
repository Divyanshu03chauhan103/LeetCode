class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n=nums.size();
        vector<vector<int>>dp(k,vector<int>(n,1));

        int result=0;
        for(int i=1;i<n;i++){
            for(int prev=0;prev<i;prev++){
                int mod = (nums[i]+nums[prev])%k;
                dp[mod][i]=max(dp[mod][i],dp[mod][prev]+1);
                result=max(dp[mod][i],result);
            }
            
        }
        return result;
    }
};