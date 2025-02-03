class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int result=1,s_inc=1,s_dec=1;

        for(int i=1;i<nums.size();i++){

            if(nums[i-1]>nums[i]){
                s_dec++;
                s_inc=1;
            }else if(nums[i-1]<nums[i]){
                s_inc++;
                s_dec=1;
            }else{
                s_inc=1;
                s_dec=1;
            }
            result=max(result,max(s_inc,s_dec));
        }
        return result;
    }
};