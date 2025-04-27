class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int i=0;
        int j=0;
        int n=nums.size();
        int result=0;
        while(j<n){

            if(j-i+1==3){
                int k=nums[i]+nums[j];
                float div = (float)nums[i+1] / 2;

                if(k==div) result++;

                i++;
            }
            j++;
        }
        return result;
    }
};