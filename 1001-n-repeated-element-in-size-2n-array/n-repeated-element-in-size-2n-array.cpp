class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        
        int N=nums.size();
        int n=N/2;
        vector<int>freq(10001,0);
        for(int i:nums){
            freq[i]++;
            if(freq[i]==n) return i;
        } 
      
        return -1;
    }
};