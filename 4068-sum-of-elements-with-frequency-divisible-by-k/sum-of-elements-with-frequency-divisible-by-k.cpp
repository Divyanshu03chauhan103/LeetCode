class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        
        vector<int>mp(101,0);
        for(int i:nums){
            mp[i]++;
        }
        
        int sum=0;
        for(int i=0;i<mp.size();i++){
            if(mp[i]%k==0){
                sum+=i*mp[i];
            }
        }
        return sum;
    }
};