class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        unordered_map<int,int>mp;

        for(auto i:nums){

            mp[i]++;
        }

        for(auto [key,val]:mp){
            if(val>1) return key;
        }
        return -1;
    }
};