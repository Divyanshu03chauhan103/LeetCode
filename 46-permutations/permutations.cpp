class Solution {
public:
    void solve(vector<vector<int>>&result,vector<int>temp,vector<int>nums){

        if(nums.size()==0){
            result.push_back(temp);
            return;
        }

        for(int i=0;i<nums.size();i++){

            temp.push_back(nums[i]);
            nums.erase(nums.begin()+i);
            solve(result,temp,nums);
             nums.insert(nums.begin() + i, temp.back());
             temp.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>>result;

        vector<int>temp;

        solve(result,temp,nums);

        return result;
    }
};