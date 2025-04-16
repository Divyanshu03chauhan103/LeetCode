class Solution {
public:
    bool solve(vector<int>& dp, vector<int>& nums, int i, int n) {
        if (dp[i] != -1) 
            return dp[i];              // reuse memoized result

        if (i == n - 1) 
            return dp[i] = true;       // at last index → can reach

        if (nums[i] == 0) 
            return dp[i] = false;      // dead end → cannot reach

        for (int step = 1; step <= nums[i]; ++step) {
            if (i + step < n && solve(dp, nums, i + step, n))
                return dp[i] = true;   // found a path → memoize true
        }

        return dp[i] = false;          // no path → memoize false
    }

    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        solve(dp, nums, 0, n);
        return dp[0];                  // only dp[0] matters
    }
};
