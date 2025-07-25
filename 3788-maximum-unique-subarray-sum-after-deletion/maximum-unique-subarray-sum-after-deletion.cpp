class Solution {
public:
    int maxSum(vector<int>& nums) {
        set<int>s;
        for(int i:nums){
            if(i>0) s.insert(i);
        }

        if(s.empty()) return *max_element(nums.begin(),nums.end());

        return accumulate(s.begin(),s.end(),0);
    }
};