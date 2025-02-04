class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        
        int result=nums[0];
        int temp_sum=nums[0];
        for(int i=1;i<nums.size();i++){

            if(nums[i]>nums[i-1]){
                temp_sum+=nums[i];
            }else{
                temp_sum=nums[i];
            }
            result=max(temp_sum,result);
        }
        return result;
    }
};