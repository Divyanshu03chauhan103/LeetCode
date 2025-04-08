class Solution {
public:
    bool check(int i,vector<int>&nums){
        unordered_set<int>s;

        for(int j=i;j<nums.size();j++){
            if(s.count(nums[j])) return false;

            s.insert(nums[j]);
        }
        return true;
    }
    int minimumOperations(vector<int>& nums) {
        
        int result=0;
        for(int i=0;i<nums.size();i+=3){

            if(check(i,nums)){
               
                return result;
            }
            result++;
        }

        return result;
    }
};