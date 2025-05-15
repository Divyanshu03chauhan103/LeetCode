class Solution {
public:
    bool f(int i, int n, int target, int partition, vector<int>& nums, vector<vector<int>>& dp) {
        if (partition > target) return false;
        if (partition == target) return true;
        if (i >= n) return false;

        if (dp[i][partition] != -1) return dp[i][partition];

        bool notTake = f(i + 1, n, target, partition, nums, dp);
        bool take = f(i + 1, n, target, partition + nums[i], nums, dp);

        return dp[i][partition] = notTake || take;
    }

    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) return false; 

        int n = nums.size();
        int target = sum / 2;

        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return f(0, n, target, 0, nums, dp);
    }
};
