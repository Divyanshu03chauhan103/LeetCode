class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long part_sum=0;
        long long result=0;

        int i=0,j=0,n=nums.size();

        while(j<n){

            part_sum+=nums[j];

            while(part_sum*(j-i+1)>=k && i<=j){
                part_sum-=nums[i];
                i++;
            }

            result+=(j-i+1);
            j++;
        }
        return result;
    }
};