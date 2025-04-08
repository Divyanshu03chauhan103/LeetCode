class Solution {
public:

    int minimumOperations(vector<int>& nums){

        unordered_set<int>s;

        for(int i=nums.size()-1;i>=0;i--){
            if(s.count(nums[i])){
                return ceil((i+1)/3.0);
            }
            s.insert(nums[i]);
        }
        return 0;
    }


    /*
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
    */
};