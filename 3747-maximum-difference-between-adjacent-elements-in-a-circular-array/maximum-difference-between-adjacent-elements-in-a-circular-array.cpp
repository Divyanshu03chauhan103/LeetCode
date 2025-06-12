class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        
        int diff=0;

        for(int i=0;i<nums.size();i++){
            if(i==nums.size()-1){
                diff=max(diff,abs(nums[i]-nums[0]));
            }else{
                diff=max(diff,abs(nums[i]-nums[i+1]));
            }
        }
        return diff;
    }
};