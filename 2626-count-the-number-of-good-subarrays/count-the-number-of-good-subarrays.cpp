class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        
        long long result=0;
        unordered_map<long long,long long>mp;
       

        int i=0;
        int j=0;
        int n=nums.size();
        int pairs=0;
        
        while(j<n){
            mp[nums[j]]++;
            
            pairs+=mp[nums[j]]-1;

         while (pairs >= k) {
                result += n - j;
                pairs -= mp[nums[i]] - 1;
                mp[nums[i]]--;
                i++;
            }


        j++;
        }

        return result;
    }
};