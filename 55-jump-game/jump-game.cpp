class Solution {
public:
    bool solve(vector<int>&dp,vector<int>&nums,int i,int n){
        if(i==n-1) return true;
        
        if(nums[i]==0) return false;
        if(dp[i]!=-1) return dp[i];
        for(int idx=1;idx<=nums[i];idx++){
            if(idx+i<n && solve(dp,nums,i+idx,n)) return dp[i]=true;
        }
        return dp[i]=false;
        }
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return solve(dp,nums,0,n);
    }
};