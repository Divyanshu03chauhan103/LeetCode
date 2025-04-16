class Solution {
public:
    bool solve(vector<int>& dp, vector<int>& nums, int i, int n) {
        if (dp[i] != -1) 
            return dp[i];             

        if (i == n - 1) 
            return dp[i] = true;       
        if (nums[i] == 0) 
            return dp[i] = false;      

        for (int step = 1; step <= nums[i]; ++step) {
            if (i + step < n && solve(dp, nums, i + step, n))
                return dp[i] = true;  
        }

        return dp[i] = false;         
    }

    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        solve(dp, nums, 0, n);
        return dp[0];                 
    }
};
