class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        
        int largest = *max_element(nums.begin(),nums.end());

        int i=0;
        int j=0;
        long long result=0;
        int n=nums.size(), count =0;

        while(j<n){
            if(nums[j]==largest) count++;

            while(count>=k){
                result+=n-j;

                if(nums[i]==largest) count--;
                i++;
            }
            j++;
        }

        return result;
    }
};