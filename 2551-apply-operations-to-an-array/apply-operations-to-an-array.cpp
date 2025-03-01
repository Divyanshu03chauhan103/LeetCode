class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        
        vector<int>result;
        int n= nums.size();
        for(int i=0;i<n-1;i++){

            if(nums[i]==nums[i+1]){
                nums[i]=nums[i]*2;
                nums[i+1]=0;
            }
        }

        for(int i=0;i<n;i++){
            if(nums[i]!=0)
                result.push_back(nums[i]);
        }

        int number_zeros= n-result.size();
        while(number_zeros){
            result.push_back(0);
            number_zeros--;
        }

        return result;
    }
};