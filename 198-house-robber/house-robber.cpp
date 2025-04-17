class Solution {
public:
    // int solve(vector<int>& nums, int i,vector<int>&dp) {
    //     if (i >= nums.size()) return 0;
    //     if(dp[i]!=-1) return dp[i];
    //     // Option 1: Rob this house and skip the next
    //     int rob = nums[i] + solve(nums, i + 2,dp);

    //     // Option 2: Skip this house
    //     int skip = solve(nums, i + 1,dp);

    //     return dp[i]=max(rob, skip);
    // }

    int rob(vector<int>& nums) {
         vector<int>dp(nums.size(),-1);
         
         dp[0]=nums[0];
         
         for(int i=1;i<nums.size();i++){

            int take=nums[i];
            if(i>1) take+=dp[i-2];

            int non_take=dp[i-1];
            dp[i]=max(take,non_take);
         }
         return dp[nums.size()-1];
    }
};
