class Solution {
public:
    int slidingWindow(vector<int>& nums,int k){

        int i=0;
        int j=0;
        int ans=0;
        int count=0;
        int n=nums.size();
        while(j<n){
            if(nums[j]%2==1){
                count++;
            }

            while(count>k){
                if(nums[i]%2==1)
                    count--;
                i++;
            }
        ans+=j-i+1;
        j++;
        }

        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return slidingWindow(nums,k)-slidingWindow(nums,k-1);
    }
};