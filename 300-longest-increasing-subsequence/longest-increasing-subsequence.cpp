class Solution {
public:
    int solve(int ind, int lastIndex, vector<int>& nums,vector<vector<int>>&dp) {
        if (ind >= nums.size()) return 0;
        if(dp[ind][lastIndex+1]!=-1) return dp[ind][lastIndex+1];
        int length = 0;
        for (int i = ind; i < nums.size(); i++) {
            if (lastIndex == -1 || nums[i] > nums[lastIndex]) {
                length = max(length, 1 + solve(i + 1, i, nums,dp));
            }
        }
        return dp[ind][lastIndex+1]=length;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));

        
        return solve(0, -1, nums,dp);
    }
};
