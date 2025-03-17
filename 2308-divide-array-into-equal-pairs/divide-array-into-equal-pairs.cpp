class Solution {
public:
    bool divideArray(vector<int>& nums) {
        
        unordered_map<int,int>mp;

        int n=nums.size();

        for(auto i:nums){
            mp[i]++;
        }

        for(auto [key,value]:mp){
            if(value%2!=0) return false;
        }
        return true;
    }
};