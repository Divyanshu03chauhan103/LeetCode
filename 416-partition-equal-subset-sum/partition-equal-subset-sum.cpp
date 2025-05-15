class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) return false; 

        int n = nums.size();
        int target = sum / 2;

        vector<vector<bool>> dp(n, vector<bool>(target + 1, false));

        for (int i = 0; i < n; ++i) {
                dp[i][target] = true;
            }

        for(int i=n-2;i>=0;i--){

            for(int partition=target-1;partition>=0;partition--){
                
                
                bool notTake = dp[i + 1][partition];
                
                bool take = (partition+nums[i]<=target) ? dp[i + 1][ partition + nums[i]]:false;
                dp[i][partition]=notTake||take;
            }
        }    

        return dp[0][0];
    }
};
