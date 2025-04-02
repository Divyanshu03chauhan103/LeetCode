class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long result=0,max_diff=0,maxele=0;
        for(int i=0;i<nums.size();i++){

             result=max(result,max_diff* 1LL*nums[i]);
             max_diff=max(max_diff,maxele-nums[i]);
             maxele=max(maxele,(long long)nums[i]);
        }
        return result;
    }
};