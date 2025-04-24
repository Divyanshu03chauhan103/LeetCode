class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        
        int i=0;
        int j=0;
        int n=nums.size();

        int unique=0;
        unordered_map<int,int>mp;

        for(int i:nums){
            mp[i]++;
        }
        unique=mp.size();

        mp.clear();

        int result=0;
        while(j<n){
            mp[nums[j]]++;

            while(mp.size()==unique){
                cout<<j;
                result+=nums.size()-j;
                mp[nums[i]]--;
                if(mp[nums[i]]==0) mp.erase(nums[i]);
                i++;
            }

            j++;
        }
        return result;
    }
};