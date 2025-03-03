class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int>result;
        int count=0;
        for(int i:nums){
            if(i<pivot){
                result.push_back(i);
            }
            else if( i== pivot)
                count++;
        }

        while(count--)
            result.push_back(pivot);
        
        for(int i: nums){
            if(i>pivot)
                result.push_back(i);
        }
        
        return result;
    }
};