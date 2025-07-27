class Solution {
public:
    int countHillValley(vector<int>& nums) {
        
        int n=nums.size();
        vector<int>prefix(n);
        vector<int>suffix(n);
        prefix[0]=nums[0];
        suffix[n-1]=nums[n-1];

        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]){
                 prefix[i]=prefix[i-1];
                 continue;
            }
            prefix[i]=nums[i-1];
        }
        for(int i=n-2;i>=0;i--){
            if(nums[i]==nums[i+1]){
                 suffix[i]=suffix[i+1];
                 continue;
            }
            suffix[i]=nums[i+1];
        }

        int result=0;
        for(int i=0;i<n-1;i++){
           while (i < n - 1 && nums[i] == nums[i + 1]) i++;

            if(prefix[i]<nums[i] && nums[i]>suffix[i]) result++;
            else if(prefix[i]>nums[i] && suffix[i]>nums[i]) result++;
            
        }
        return result;
    }
};