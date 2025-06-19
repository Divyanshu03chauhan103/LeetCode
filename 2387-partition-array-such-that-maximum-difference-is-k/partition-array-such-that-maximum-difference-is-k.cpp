class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int max_element=INT_MIN;
        int min_element=INT_MAX;
        sort(nums.begin(),nums.end());
        int result=0;
        for(int i=0;i<nums.size();i++){

            max_element=max(max_element,nums[i]);
            min_element=min(min_element,nums[i]);

            if(max_element-min_element>k){
                max_element=nums[i];
                min_element=nums[i];
                result++;
            }
        }
        result++;
        return result;
    }
};