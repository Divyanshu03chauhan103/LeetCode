class Solution {
public:
    int slidingWindow(vector<int>&nums,int k){
        unordered_map<int,int>mp;

        int i=0;
        int j=0;
        int ans=0;
        int n=nums.size();
        while(j<n){
            mp[nums[j]]++;

            while(mp.size()>k){
                mp[nums[i]]--;
                if(mp[nums[i]]==0)
                    mp.erase(nums[i]);
                i++;
            }

            ans+=j-i+1;
            j++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return slidingWindow(nums,k)-slidingWindow(nums,k-1);
    }
};