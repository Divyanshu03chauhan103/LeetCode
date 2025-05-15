class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) return false; 

        int n = nums.size();
        int target = sum / 2;

        vector<bool> dp(target+1,  false);

            dp[target] = true;
            

        for(int i=n-1;i>=0;i--){

                vector<bool>curr(target+1,false);
                curr[target]=true;
            for(int partition=target-1;partition>=0;partition--){
                
                
                bool notTake = dp[partition];
                
                bool take = (partition+nums[i]<=target) ? dp[ partition + nums[i]]:false;

                curr[partition]=notTake||take;
            }
            
            dp=curr;
        }    

        return dp[0];
    }
};
