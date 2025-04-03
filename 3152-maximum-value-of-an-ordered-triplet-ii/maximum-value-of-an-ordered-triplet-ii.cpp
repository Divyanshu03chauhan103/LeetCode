class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long max_diff=0,max_ele=0,result=0;

        for(auto i:nums){
            result=max(result,max_diff*i);
            max_diff=max(max_diff,max_ele-i);
            max_ele=max(max_ele,(long long)i);

        }
        return result;
    }
};