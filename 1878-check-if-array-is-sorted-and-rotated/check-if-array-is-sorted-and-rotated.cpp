class Solution {
public:
    bool check(vector<int>& nums) {
        
        int count=0;
        int  n=nums.size();
        if(nums[0]<nums[n-1]) count++;
        for(int i=1;i<n;i++){

            if(nums[i-1]>nums[i])
                count++;
        }

        return count>1? false:true;
    }
};