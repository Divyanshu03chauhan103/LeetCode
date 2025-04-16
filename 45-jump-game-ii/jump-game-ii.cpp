class Solution {
public:
    int solve(vector<int>&dp,vector<int>&nums,int i,int n){
        if(i>=n-1) return 0;
        if(i==n-2) return dp[i]=1;

        int min_steps= INT_MAX;
        if(dp[i]!=-1) return dp[i];
        for(int j=1;j<=nums[i];j++){

            int steps=solve(dp,nums,i+j,n);
            if(steps!=INT_MAX)
            min_steps=min(steps+1,min_steps);
        }

        return dp[i]=min_steps;
    }
    int jump(vector<int>& nums) {
        
        int n=nums.size();
        vector<int>dp(n,-1);
        return solve(dp,nums,0,n);
    }
};