class Solution {
public:
    int maximumDifference(vector<int>& nums) {

        int n=nums.size();
        int result=0;
        int smallest=INT_MAX;

        for(int i=0;i<n;i++){
            if(smallest>nums[i])
                smallest=nums[i];
            else
                result=max(result,nums[i]-smallest);
        }

        return result==0?-1:result;

    }
};