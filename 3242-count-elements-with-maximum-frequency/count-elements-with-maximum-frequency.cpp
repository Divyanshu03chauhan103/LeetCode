class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int>freq(101,0);
        int max_freq=0;
        for(int i:nums){
            freq[i]++;
            max_freq=max(max_freq,freq[i]);
        }

        int result=0;
        for(int i:freq){
            result+= (i==max_freq)?i:0;
        }
        return result;
    }
};