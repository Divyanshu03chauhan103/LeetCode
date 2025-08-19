class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        
        long long result=0;

        int i=0;
        int j=0;
        int n=nums.size();

        while(j<n){
            if(nums[j]!=0){
                j++;
                i=j;
                
            }
            else{
                result+=(j-i+1);
                j++;
            }
        }
        return result;
    }
};