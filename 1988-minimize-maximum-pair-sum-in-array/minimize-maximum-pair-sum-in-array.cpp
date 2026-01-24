class Solution {
public:
    int minPairSum(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());

        int result=-1e9;

        int i=0;
        int j=nums.size()-1;
        while(i<j){
            result=max(result,nums[i]+nums[j]);
            i++;
            j--;
        }
        return result;

    }
};