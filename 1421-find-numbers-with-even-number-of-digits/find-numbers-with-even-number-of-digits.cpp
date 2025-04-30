class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int result=0;
        for(auto i:nums){
            if((int)(floor(log10(i))+1) % 2 == 0 ) result++;
        }

        return result;
    }
};